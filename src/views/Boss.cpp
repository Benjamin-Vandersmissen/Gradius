//
// Created by benji on 7/06/18.
//

#include "Boss.h"


void views::Boss::update(){
    auto model = std::dynamic_pointer_cast<models::Ship>(m_model);
    if(model){
        if(model->isImmune())
            m_animation = m_invincible;
        else
            m_animation = m_normal;
    }
    Entity::update();
}