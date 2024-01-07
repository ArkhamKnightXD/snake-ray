#include "food.h"
#include <raylib.h>

Food::Food(float positionX, float positionY)
{
    position = GenerateRandomPosition();

    Image image = LoadImage("assets/img/food.png");

    sprite = LoadTextureFromImage(image);

    UnloadImage(image);
}

Vector2 Food::GenerateRandomPosition()
{
    //Raylib method to get random values, between indicated values
    float positionX = GetRandomValue(0, 24);
    float positionY = GetRandomValue(0, 24);

    return Vector2{positionX, positionY};
}

void Food::Update()
{

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
