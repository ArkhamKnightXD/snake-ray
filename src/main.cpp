#include <raylib.h>
#include "Food.h"
#include "Snake.h"

int main()
{
    int cellsize = 30;
    int cellCount = 25;

    InitWindow(cellsize * cellCount, cellsize * cellCount, "Snake!");
    SetTargetFPS(60);

    Food food = Food(cellCount, cellsize);
    Snake snake = Snake(cellCount, cellsize);

    while (!WindowShouldClose())
    {
        snake.Update();

        food.isDestroyed = snake.CheckCollisionWithFood(food.position);
        
        food.Update();
        
        BeginDrawing();

            ClearBackground({20, 160, 133, 255});

            food.Draw();
            snake.Draw();

        EndDrawing();
    }

    CloseWindow();
}