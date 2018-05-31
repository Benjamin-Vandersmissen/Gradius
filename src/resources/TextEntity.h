//
// Created by benji on 31/05/18.
//

#ifndef GRADIUS_RESOURCES_TEXTENTITY_H
#define GRADIUS_RESOURCES_TEXTENTITY_H

#include "Entity.h"
#include "../models/TextEntity.h"
#include "../controllers/ScrollingEntity.h"
#include "../models/ScrollingEntity.h"
#include "../views/TextEntity.h"

namespace resources {
    class TextEntity : public Entity{
    private:
        std::string m_text;
        std::string m_fontPath;
        std::shared_ptr<sf::Font> m_font;
    public:
        void loadFromIni(const std::string &path, const ini::Configuration &configuration) override;

        model_ptr create(const std::pair<float, float> &position) override;
    };
}


#endif //GRADIUS_RESOURCES_TEXTENTITY_H
