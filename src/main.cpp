#include <raylib.h>
#include "food.h"
#include "snake.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    int cellsize = 30;
    int cellCount = 25;

    InitWindow(cellsize * cellCount, cellsize * cellCount, "Snake!");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        snake.Update();

        food.isDestroyed = snake.CheckCollisionWithFood(food.position);
        
        food.Update();
        
        BeginDrawing();

            ClearBackground(darkGreen);

            food.Draw();
            snake.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}