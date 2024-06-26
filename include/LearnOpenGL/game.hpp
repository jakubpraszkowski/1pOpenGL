#pragma once

class Game {
public:
    float getDeltaTime() const;
    float getLastFrame() const;

private:
    float deltaTime = 0.0f, lastFrame = 0.0f;

};