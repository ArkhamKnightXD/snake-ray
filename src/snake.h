#pragma once

#include <raylib.h>
#include <deque>

class Snake
{
public:
    Snake();
    void Update();
    void Draw();

public:
    //a deque is a data structure that can be use to get elements from both 
    // sides of the list is a combination of stacks and queue
    std::deque<Vector2> body;
    Vector2 direction;
};