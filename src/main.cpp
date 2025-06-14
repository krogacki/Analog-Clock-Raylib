#include <raylib.h>
#include "AnalogClock.hpp"

int main() 
{
    const Color LIGHT_BLUE = {255, 239, 240, 255};
    
    constexpr int screenWidth = 600;
    constexpr int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Analog Clock");
    SetTargetFPS(15);

    // AnalogClock clock {250, {300, 300}};
    AnalogClock clock = AnalogClock(250, {300, 300});
    
    while (!WindowShouldClose())
    {
        // 1. Event Handlig

        // 2. Updating

        // 3. Drawing
        BeginDrawing();
        ClearBackground(LIGHT_BLUE);
        clock.Draw();
        clock.Update();
        EndDrawing();
    }
    
    CloseWindow();
}