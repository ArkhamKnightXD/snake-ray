#include "food.h"

Food::Food()
{
    position = GenerateRandomPosition();

    Image image = LoadImage("assets/img/food.png");

    sprite = LoadTextureFromImage(image);

    UnloadImage(image);

    isDestroyed = false;
}

//We need to validate that the position of the food doesn't correspond with one within the body
Vector2 Food::GenerateRandomPosition()
{
    //Raylib method to get random values, between indicated values
    float positionX = GetRandomValue(0, 24);
    float positionY = GetRandomValue(0, 24);

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
    //cellsize = 30
    DrawTexture(sprite, position.x * 30, position.y * 30, WHITE);
}

//Object destructor
Food::~Food()
{
    UnloadTexture(sprite);
}
