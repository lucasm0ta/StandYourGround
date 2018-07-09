#ifndef HUD_H
#define HUD_H

#include "Component.h"
#include "GameObject.h"
#include "Elfa.h"
#include "GameTimer.h"
#include "../include/SideItemBar.h"
#include "../include/SkillBar.h"

class HUD : public Component {
    public:
        HUD(GameObject& associated, Elfa* player);

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        std::string Type();
        void NotifyCollision(GameObject &other);

        bool GameOver();
        bool UseTrap(std::string trap);
    private:
        Elfa* player;
        GameTimer* timer;
        SideItemBar* sideItemBar;
        SkillBar* skillBar;

        std::vector<GameObject*> hudComponents;
};

#endif