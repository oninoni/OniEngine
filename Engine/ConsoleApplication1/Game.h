#pragma once

class GameObject;
class Camera;

class Game {
private:
    Camera* camera;

    GameObject* root;
public:
    Game();
    virtual ~Game() = 0;

    virtual void init();
    virtual void update(const double & delta, InputManager* input);

    GameObject* getRootGameObject();

    Camera* getCamera();
};

