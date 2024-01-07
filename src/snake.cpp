#include "snake.h"
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
    body = {{6, 9}, {5, 9}, {4, 9}};
    direction = {1, 0};
    shouldAddSegment = false;
    isGameOver = false;
}

void Snake::Update()
{
    if (eventTriggered(0.2))
    {
        if (!shouldAddSegment)
        {
            // we remove the last element (The tail of the snake) and we push at the head the head + the direction
            body.pop_back();
            body.push_front(Vector2Add(body[0], direction));
        }
        else
        {
            //its better to add the new element at the head, cuz this gives a better visual effect.
            // When the element is added we need to stop the snake movement, to complete the visual effect.
            body.push_front(Vector2Add(body[0], direction));

            shouldAddSegment = false;
        }
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

    CheckCollisionWithEdges();

    CheckCollisionBetweenHeadAndBody();
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

bool Snake::CheckCollisionWithFood(Vector2 position)
{
    if (Vector2Equals(body[0], position))
    {
        shouldAddSegment = true;
        return true;   
    }

    return false;
}

void Snake::CheckCollisionWithEdges()
{
    if (body[0].x == 25 || body[0].x == -1 || body[0].y == 25 || body[0].y == -1)
    {
        ResetPosition();
    }
}

void Snake::CheckCollisionBetweenHeadAndBody()
{
    for (unsigned int i = 1; i < body.size(); i++)
    {
        if (Vector2Equals(body[0], body[i]))
        {
            ResetPosition();
        }
    }
}

void Snake::ResetPosition()
{
    body = {{6, 9}, {5, 9}, {4, 9}};
    direction = {1, 0};
}
