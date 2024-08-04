#pragma once

#include <raylib.h>

class Food
{
public:
    Food(int cellCount, int cellSize);
    void Update();
    void Draw();
    Vector2 GenerateRandomPosition();

public:
    int cellCount;
    int cellSize;
    Vector2 position;
    bool isDestroyed;
};