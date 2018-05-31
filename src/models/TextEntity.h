//
// Created by benji on 31/05/18.
//

#ifndef GRADIUS_MODELS_TEXTENTITY_H
#define GRADIUS_MODELS_TEXTENTITY_H

#include "ScrollingEntity.h"
#include "../resources/TextEntity.h"


namespace resources{
    class TextEntity;
}

namespace models {
    class TextEntity : public ScrollingEntity{
    protected:
        std::string m_value;
    public:
        friend class resources::TextEntity;

        void update() override ;

        std::string text(){
            return m_value;
        }
    };
}


#endif //GRADIUS_MODELS_TEXTENTITY_H
