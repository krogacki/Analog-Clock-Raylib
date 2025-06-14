#pragma once
#include <raylib.h>
#include <ctime>

class AnalogClock {

public:
    AnalogClock(int size, Vector2 position) : m_size(size), m_position(position), m_hour(0), m_minute(0), m_second(0) {};
    void Draw() const;
    void Update();
    
private:
    void DrawFace() const;
    void DrawHourMarks() const;
    void DrawMinuteHand(int minute) const;
    void DrawHourHand(int hour, int minute) const;
    void DrawHand(float handWidth, float handLength, int angle, Color color, int offset) const;
    void DrawSecondHand(int second) const;
    int m_size;
    Vector2 m_position;
    int m_hour;
    int m_minute;
    int m_second;
};