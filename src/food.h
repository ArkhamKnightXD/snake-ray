#pragma once

#include <raylib.h>

class Food
{
public:
    Food(float positionX, float positionY);
    void Update();
    void Draw();
    Vector2 GenerateRandomPosition();
    ~Food();

public:
    Vector2 position;
    Texture2D sprite;
};