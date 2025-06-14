#include "AnalogClock.hpp"

void AnalogClock::Draw() const
{
    DrawFace();
    DrawHourMarks();
    DrawHourHand(m_hour, m_minute);
    DrawMinuteHand(m_minute);
    DrawSecondHand(m_second);
    DrawCircleV(m_position, 15, DARKGRAY);
}

void AnalogClock::Update()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    m_hour = now->tm_hour % 12;
    m_minute = now->tm_min;
    m_second = now->tm_sec;
} 

void AnalogClock::DrawFace() const 
{
    DrawCircleV(m_position, m_size, DARKGRAY);
    DrawCircleV(m_position, m_size - 30, LIGHTGRAY);
    DrawCircleV(m_position, m_size - 40, RAYWHITE);
}

void AnalogClock::DrawHourMarks() const
{
    float rectWidth = 10;
    float rectHeight = m_size;

    Rectangle rect = {m_position.x, m_position.y, rectWidth, rectHeight};
    for (int i = 0; i < 12; i++) 
    {
        DrawRectanglePro(rect, {rectWidth/2, rectHeight}, i*30, DARKGRAY);
    }
    DrawCircleV(m_position, m_size - 50, RAYWHITE);
    DrawCircleV(m_position, 5, RED);
}

void AnalogClock::DrawMinuteHand(int minute) const
{
    float handWidth = 10;
    float handLength = m_size * 0.7;

    Rectangle handRect = Rectangle{m_position.x, m_position.y, handWidth, handLength};
    int angle = minute * 6;

    DrawRectanglePro(handRect, {handWidth/2, handLength}, angle, DARKGRAY);
}

void AnalogClock::DrawHand(float handWidth, float handLength, int angle, Color color, int offset) const
{
    Rectangle handRect = Rectangle{m_position.x, m_position.y, handWidth, handLength};
    DrawRectanglePro(handRect, {handWidth/2, handLength - offset}, angle, color);
}

void AnalogClock::DrawHourHand(int hour, int minute) const
{
    float handWidth = 15;
    float handLength = m_size * 0.5;
    int angle = 30 * hour + (minute / 60.0) * 30;

    DrawHand(handWidth, handLength, angle, DARKGRAY, 0);
}

void AnalogClock::DrawSecondHand(int second) const
{
    float handWidth = 5;
    float handLength = m_size * 1.05;
    int angle = second * 6;
    DrawHand(handWidth, handLength, angle, RED, 55);
}