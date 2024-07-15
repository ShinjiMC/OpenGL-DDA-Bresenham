#include "car.hpp"
#include <GL/glut.h>
#include <memory>

Car::Car(float cx, float cy, int width, int height, std::string lineType, std::string technique)
    : centerX(cx), centerY(cy), width(width), height(height), lineType(lineType), technique(technique) {}

void Car::drawLine(float r, float g, float b, float x1, float y1, float x2, float y2)
{
    if (technique == "DDA")
    {
        DDA line(r, g, b, x1, y1, x2, y2, lineType);
        line.drawLine();
    }
    else if (technique == "Bresenham")
    {
        Bresenham line(r, g, b, x1, y1, x2, y2, lineType);
        line.drawLine();
    }
}

void Car::draw()
{
    // Car body
    drawLine(1.0f, 1.0f, 0.0f, centerX - (0.5f * width), centerY - (0.2f * height), centerX + (0.5f * width), centerY - (0.2f * height));
    drawLine(1.0f, 1.0f, 0.0f, centerX + (0.5f * width), centerY - (0.2f * height), centerX + (0.5f * width), centerY);
    drawLine(1.0f, 1.0f, 0.0f, centerX + (0.5f * width), centerY, centerX - (0.5f * width), centerY);
    drawLine(1.0f, 1.0f, 0.0f, centerX - (0.5f * width), centerY, centerX - (0.5f * width), centerY - (0.2f * height));

    // Car roof (changed to red)
    drawLine(1.0f, 0.0f, 0.0f, centerX - (0.3f * width), centerY, centerX - (0.1f * width), centerY + (0.2f * height));
    drawLine(1.0f, 0.0f, 0.0f, centerX - (0.1f * width), centerY + (0.2f * height), centerX + (0.1f * width), centerY + (0.2f * height));
    drawLine(1.0f, 0.0f, 0.0f, centerX + (0.1f * width), centerY + (0.2f * height), centerX + (0.3f * width), centerY);

    // Car wheels (changed to white)
    // Front wheel
    drawLine(1.0f, 1.0f, 1.0f, centerX - (0.3f * width), centerY - (0.2f * height), centerX - (0.25f * width), centerY - (0.3f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX - (0.25f * width), centerY - (0.3f * height), centerX - (0.2f * width), centerY - (0.2f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX - (0.2f * width), centerY - (0.2f * height), centerX - (0.25f * width), centerY - (0.1f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX - (0.25f * width), centerY - (0.1f * height), centerX - (0.3f * width), centerY - (0.2f * height));

    // Rear wheel
    drawLine(1.0f, 1.0f, 1.0f, centerX + (0.3f * width), centerY - (0.2f * height), centerX + (0.25f * width), centerY - (0.3f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX + (0.25f * width), centerY - (0.3f * height), centerX + (0.2f * width), centerY - (0.2f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX + (0.2f * width), centerY - (0.2f * height), centerX + (0.25f * width), centerY - (0.1f * height));
    drawLine(1.0f, 1.0f, 1.0f, centerX + (0.25f * width), centerY - (0.1f * height), centerX + (0.3f * width), centerY - (0.2f * height));
}
