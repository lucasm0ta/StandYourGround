#include "../include/Elfa.h"
#include "../include/InputManager.h"
#include "../include/SpriteVector.h"

Elfa* Elfa::elfa = nullptr;

Elfa::Elfa(GameObject& associated) : Component(associated), 
                                     hp(100), direction("esq"), 
                                     facing("frente"), movement("idle") {
}

Elfa::~Elfa() {

}

void Elfa::Start() {

}


void Elfa::Update(float dt) {
    InputManager &inp = InputManager::GetInstance();
    velX = 0;
    velY = 0;
    // Seta o state do personagem que indica qual sprite sera renderizada
    // State sera movement + facing + direction
    if(inp.IsKeyDown(A_KEY)) {
        movement = "run";
        direction = "esq";
        facing = "frente";
        velX = -VELOCITY*dt;
    } else if(inp.IsKeyDown(D_KEY)) {
        movement = "run";
        direction = "dir";
        facing = "frente";
        velX = VELOCITY*dt;
    } else {
        movement = "idle";
    }

    if(inp.IsKeyDown(W_KEY)) {
        movement = "run";
        facing = "costa";
        velY = -VELOCITY*dt;
    } else if(inp.IsKeyDown(S_KEY)) {
        movement = "run";
        facing = "frente";
        velY = VELOCITY*dt;
    } else {
        if (movement != "run") // Se o run for setado somente no A e D ele nao deixa idle aqui
            movement = "idle";
    }
    associated.box.Shift({velX, velY});
    
}

void Elfa::Render() {

}

bool Elfa::Is(std::string type) {
    return type == "Elfa";
}

std::string Elfa::Type() {
    return "Elfa";
}

void Elfa::NotifyCollision(GameObject &other) {

}

std::string Elfa::GetState() {
    return movement + "_" + facing + "_" + direction;
}
