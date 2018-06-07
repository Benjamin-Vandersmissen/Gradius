//
// Created by benji on 7/06/18.
//

#include "Boss_1.h"
#include "../models/Boss_1.h"

void controllers::Boss_1::update() {
    auto model = std::dynamic_pointer_cast<models::Boss_1>(m_model);
    if(m_stage != EnteringBattlefield){
        if(model->position().second > 1.3 or model->position().second < -2.2){ //reached desired position
            m_direction *= -1; //move other direction
        }
        m_currentDirection = {0, 0.75*m_direction};
    }

    switch (m_stage) {
        case Stage ::EnteringBattlefield:{
            if (!model->hasBossImmunity()){
                m_stage = Stage::Firing;
                m_startPosition = model->position();
            }
            break;
        }
        case Stage::Firing:{
            if(model->isImmune()) {
                m_stage = Stage::DamageTaken;
            }
            else{
                fire();
            }
            break;
        }
        case Stage::DamageTaken:{
            spawnMinions();
            m_currentDirection = {0,0};
            m_stage = Stage::Invincible;
            break;
        }
        case Stage::Invincible:{
            if(!model->isImmune()){
                m_stage = Stage::Firing;
            }
        }
    }
    Boss::update();
}

void controllers::Boss_1::spawnMinions() {
    auto model = std::dynamic_pointer_cast<models::Boss_1>(m_model);
    auto type = model->getMinionType();
    for(int i = 0; i < 6; ++i){
        resources::map[type]->create(std::pair<float, float>{model->position().first + 5, float(-2+0.6*i)});
    }
}
