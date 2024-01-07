#pragma once

//I only need to make the include in this header file, it is not necessary
//  to write the include in the cpp file
#include <raylib.h>
#include <deque>

class Snake
{
public:
    Snake(int cellCount, int cellSize);
    void Update();
    void Draw();
    bool CheckCollisionWithFood(Vector2 position);
    void CheckCollisionWithEdges();
    void CheckCollisionBetweenHeadAndBody();
    void ResetPosition();

public:
    int cellCount;
    //I define this as a float to avoid casting warning 
    float cellSize;
    
    //a deque is a data structure that can be use to get elements from both 
    // sides of the list is a combination of stacks and queue
    std::deque<Vector2> body;
    Vector2 direction;
    bool shouldAddSegment;
    bool isGameOver;
};