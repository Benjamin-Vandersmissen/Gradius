//
// Created by benji on 3/06/18.
//

#include "Boss.h"
#include "../controllers/Boss_1.h"
#include "../models/Boss_1.h"

model_ptr resources::Boss::create(const std::pair<float, float> &position) {
    std::shared_ptr<models::Boss> model;
    std::shared_ptr<controllers::Boss> controller;
    switch(m_bossType){
        case 1:{
            model = std::make_shared<models::Boss_1>();
            controller = std::make_shared<controllers::Boss_1>();
            std::dynamic_pointer_cast<models::Boss_1>(model)->m_minion = m_minionType;
            break;
        }
    }
    model->m_speed = m_speed;
    model->m_bulletType = m_bulletType;
    model->m_maxLives= m_maxLives;
    model->m_lives = m_maxLives;
    model->m_maxImmunity = m_maxImmunity;
    auto view = std::make_shared<views::Boss>();
    view->m_heartTexture = m_heartTexture;

    controller->m_maxFireCooldown = m_fireCooldown;
    finalizeCreation(view, model, controller, position);
    view->m_normal = m_animation;
    view->m_invincible = m_invincibleAnimation;
    return model;
}

void resources::Boss::loadFromIni(const std::string &path, const ini::Configuration &configuration) {
    EnemyShip::loadFromIni(path, configuration);
    m_invincibleAnimation = Animation(0);
    m_invincibleAnimation.createFromStrip(configuration["Boss"]["InvincibleAnimation"].as_string_or_default(path+"../resources/textures/boss_1_shielded.png"),1);

    m_bossType = configuration["Boss"]["Type"].as_int_or_default(1);
    m_minionType = configuration["Boss"]["MinionType"].as_string_or_default("EnemyShip");
}
