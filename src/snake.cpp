#include "snake.h"
#include <raylib.h>
#include <raymath.h>

double lastUpdateTime = 0;

// method for control the speed that the snake has to move.
bool eventTriggered(double interval)
{

    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;

        return true;
    }

    return false;
}

Snake::Snake()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}

void Snake::Update()
{

    if (eventTriggered(0.2))
    {
        // we remove the last element (The tail of the snake) and we push at the head the head + the direction
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }

    if (IsKeyPressed(KEY_D) && direction.x != -1)
    {
        direction = {1, 0};
    }

    if (IsKeyPressed(KEY_A) && direction.x != 1)
    {
        direction = {-1, 0};
    }

    if (IsKeyPressed(KEY_W) && direction.y != 1)
    {
        direction = {0, -1};
    }

    if (IsKeyPressed(KEY_S) && direction.y != -1)
    {
        direction = {0, 1};
    }
}

void Snake::Draw()
{
    // I use unsingned to avoid the warning of comparing the index with the body.size
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float positionX = body[i].x;
        float positionY = body[i].y;

        Rectangle bounds = {positionX * 30, positionY * 30, 30, 30};

        DrawRectangleRounded(bounds, 0.5, 6, BLACK);
    }
}
