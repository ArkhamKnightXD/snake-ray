#pragma once

#include <raylib.h>

class Food
{
public:
    Food(int cellCount, int cellSize);
    void Update();
    void Draw();
    Vector2 GenerateRandomPosition();
    ~Food();

public:
    int cellCount;
    int cellSize;
    Vector2 position;
    Texture2D sprite;
    bool isDestroyed;
};