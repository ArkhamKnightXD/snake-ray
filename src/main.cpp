#include <raylib.h>
#include "Snake.h"

const int CELL_SIZE = 23;
int CELL_COUNT = 23;

int playerScore;

typedef struct
{
    int cellCount;
    int cellSize;
    Vector2 position;
    bool isDestroyed;
} Food;

Vector2 generateRandomPosition()
{
    float positionX = GetRandomValue(0, CELL_COUNT - 1);
    float positionY = GetRandomValue(0, CELL_COUNT - 1);

    return Vector2{positionX, positionY};
}

int main()
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Snake!");
    SetTargetFPS(60);

    Vector2 initialFoodPosition = generateRandomPosition();

    Food food = {CELL_COUNT, CELL_SIZE, initialFoodPosition, false};

    Snake snake = Snake(CELL_COUNT, CELL_SIZE);

    InitAudioDevice();

    Sound eatFoodSound = LoadSound("assets/sounds/okay.wav");

    while (!WindowShouldClose())
    {
        snake.Update();

        food.isDestroyed = snake.CheckCollisionWithFood(food.position);

        if (food.isDestroyed)
        {
            food.position = generateRandomPosition();
            playerScore++;
            PlaySound(eatFoodSound);
        }

        if (snake.isGameOver)
        {
            playerScore = 0;
        }

        BeginDrawing();

        ClearBackground({20, 160, 133, 255});

        DrawText(TextFormat("%i", playerScore), 250, 20, 40, BLACK);

        DrawRectangle(food.position.x * CELL_SIZE, food.position.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, BLACK);

        snake.Draw();

        EndDrawing();
    }

    UnloadSound(eatFoodSound);
    CloseWindow();
}