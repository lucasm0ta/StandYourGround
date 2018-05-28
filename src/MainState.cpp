#include "../include/MainState.h"
#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "../include/CameraFollower.h"
#include "../include/InputManager.h"
#include "../include/SpriteVector.h"
#include "../include/Elfa.h"

MainState::MainState() : goElfa(std::make_shared<GameObject>()) {
    auto bgObj = std::make_shared<GameObject>();
    objectArray.push_back(bgObj);
    bgObj->box.SetOrigin(0, 0);
    bgObj->box.SetSize(1024, 600);
    Sprite *spr = new Sprite(*bgObj, "./assets/img/ocean.jpg");
    bgObj->AddComponent(spr);
    CameraFollower *followerBg = new CameraFollower(*bgObj);
    bgObj->AddComponent(followerBg);
    bgObj->box.SetOrigin(0, 0);
    bgObj->box.SetSize(1024, 600);

    goElfa->box.SetOrigin(30, 30);
    SpriteVector *vector = new SpriteVector(*goElfa);
    vector->AddSprite("idle_frente_esq", "./assets/img/elfa/idle/elfa_idle_esq.png", 10, 0.11, 0.0, {4, 4});
    vector->AddSprite("run_frente_dir", "./assets/img/elfa/correndo/elfa_run_dir.png", 4, 0.11, 0.0, {4, 4});
    vector->AddSprite("run_frente_esq", "./assets/img/elfa/correndo/elfa_run_esq.png", 4, 0.11, 0.0, {4, 4});
    vector->AddSprite("idle_frente_dir", "./assets/img/elfa/idle/elfa_idle_dir.png", 10, 0.11, 0.0, {4, 4});
    
    vector->AddSprite("run_costa_dir", "./assets/img/elfa/correndo/elfa_run_costa_dir.png", 4, 0.11, 0.0, {4, 4});
    vector->AddSprite("idle_costa_dir", "./assets/img/elfa/idle/elfa_idle_costa_dir.png", 5, 0.11, 0.0, {4, 4});
    vector->AddSprite("run_costa_esq", "./assets/img/elfa/correndo/elfa_run_costa_esq.png", 4, 0.11, 0.0, {4, 4});
    vector->AddSprite("idle_costa_esq", "./assets/img/elfa/idle/elfa_idle_costa_esq.png", 5, 0.11, 0.0, {4, 4});
    goElfa->AddComponent(vector);
    Elfa* player = new Elfa(*goElfa);
    goElfa->AddComponent(player);
    objectArray.push_back(goElfa);
}

MainState::~MainState() {

}


void MainState::LoadAssets() {

}

bool MainState::QuitRequested() {
    return quitRequested;
}

void MainState::Update(float dt) {
    InputManager &inp = InputManager::GetInstance();
    if (inp.QuitRequested()) {
        quitRequested = true;
    }
    if (inp.KeyPress(ESCAPE_KEY)) {
        quitRequested = true;
    }
    Elfa *elfa = (Elfa *) goElfa->GetComponent("Elfa");
    SpriteVector *sprVec = (SpriteVector *) goElfa->GetComponent("SpriteVector");
    if(elfa != nullptr && sprVec != nullptr) {
        sprVec->SetCurSprite(elfa->GetState());
    }
    UpdateArray(dt);
}

void MainState::Render() {
    RenderArray();
}


void MainState::Start() {
    LoadAssets();
    for (unsigned int i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Start();
        // std::cout<<"STARTED!:"<<i<<std::endl;
    }
    started = true;
}

void MainState::Pause() {

}

void MainState::Resume() {

}