#include <raylib.h>
#include "player.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 750;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Snake!");
    SetTargetFPS(60);

    Player player = Player(10, screenHeight / 2);


    while (!WindowShouldClose())
    {

        player.Update();
        
        BeginDrawing();

            ClearBackground(darkGreen);

            player.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}