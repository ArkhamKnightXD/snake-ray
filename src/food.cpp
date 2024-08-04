#include "Food.h"

Food::Food(int cellCount, int cellSize)
{
    this->cellCount = cellCount;
    this->cellSize = cellSize;

    position = GenerateRandomPosition();

    isDestroyed = false;
}

//We need to validate that the position of the food doesn't correspond with one within the body
Vector2 Food::GenerateRandomPosition()
{
    //Raylib method to get random values, between indicated values
    float positionX = GetRandomValue(0, cellCount - 1);
    float positionY = GetRandomValue(0, cellCount - 1);

    return Vector2{positionX, positionY};
}

void Food::Update()
{
    if (isDestroyed)
    {
        position = GenerateRandomPosition();
    }
}

void Food::Draw()
{
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLACK);
}
