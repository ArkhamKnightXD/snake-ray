#include <raylib.h>
#include "Snake.h"
#include <fstream>

const int CELL_SIZE = 23;
const int CELL_COUNT = 23;

const int SCREEN_WIDTH = CELL_SIZE * CELL_COUNT;
const int SCREEN_HEIGHT = CELL_SIZE * CELL_COUNT;

int score;
int highScore;

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

void saveScore()
{
    std::ofstream highScores("high-score.txt");

    std::string scoreString = std::to_string(score);
    highScores << scoreString;

    highScores.close();
}

int loadHighScore()
{
    std::string highScoreText;

    std::ifstream highScores("high-score.txt");

    if (!highScores.is_open())
    {
        saveScore();

        std::ifstream auxHighScores("high-score.txt");

        getline(auxHighScores, highScoreText);

        highScores.close();

        int highScore = stoi(highScoreText);

        return highScore;
    }

    getline(highScores, highScoreText);

    highScores.close();

    int highScore = stoi(highScoreText);

    return highScore;
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake!");
    SetTargetFPS(60);

    highScore = loadHighScore();

    Vector2 initialFoodPosition = generateRandomPosition();

    Food food = {CELL_COUNT, CELL_SIZE, initialFoodPosition, false};

    Snake snake = Snake(CELL_COUNT, CELL_SIZE);

    InitAudioDevice();

    Sound eatFoodSound = LoadSound("assets/sounds/okay.wav");

    bool isGamePaused = false;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            isGamePaused = !isGamePaused;
            PlaySound(eatFoodSound);
        }

        if (!isGamePaused)
        {
            snake.Update();
        }

        food.isDestroyed = snake.CheckCollisionWithFood(food.position);

        if (food.isDestroyed)
        {
            food.position = generateRandomPosition();
            score++;
            PlaySound(eatFoodSound);
        }

        if (snake.isGameOver)
        {
            if (score > highScore)
            {
                highScore = score;

                saveScore();
            }

            score = 0;
        }

        BeginDrawing();

        ClearBackground({20, 160, 133, 255});

        DrawText(TextFormat("Score: %i", score), SCREEN_WIDTH / 2 + 90, 20, 22, BLACK);
        DrawText(TextFormat("High Score %i", highScore), 50, 20, 22, BLACK);

        if (isGamePaused)
        {
            DrawText("Game Paused", 130, 60, 40, BLACK);
        }

        DrawRectangle(food.position.x * CELL_SIZE, food.position.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, BLACK);

        snake.Draw();

        EndDrawing();
    }

    UnloadSound(eatFoodSound);
    CloseWindow();
}