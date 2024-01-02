#include "player.h"
#include <raylib.h>

Player::Player(float positionX, float positionY)
{
    bounds = Rectangle{positionX, positionY, 16, 64};
    speed = 8;
    score = 0;
}

void Player::Update()
{
    if (IsKeyDown(KEY_W) && bounds.y >= 0)
        bounds.y -= speed;

    if (IsKeyDown(KEY_S) && bounds.y <= GetScreenHeight() - bounds.height)
        bounds.y += speed;
}

void Player::Draw()
{
    DrawRectangleRounded(bounds, 0.8, 0, WHITE);
}