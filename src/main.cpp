#include <raylib.h>
#include "food.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    int cellsize = 30;
    int cellCount = 25;

    InitWindow(cellsize * cellCount, cellsize * cellCount, "Snake!");
    SetTargetFPS(60);

    Food food = Food(5, 6);

    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(darkGreen);

            food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}