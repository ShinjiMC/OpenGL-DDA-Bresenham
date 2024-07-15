#include "house.hpp"
#include <GL/glut.h>
#include <memory>

House::House(float cx, float cy, float width, float height, std::string lineType, std::string technique)
    : centerX(cx), centerY(cy), width(width), height(height), lineType(lineType), technique(technique) {}

void House::drawLine(float r, float g, float b, float x1, float y1, float x2, float y2)
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

void House::draw()
{
    // Roof
    drawLine(1.0f, 0.0f, 0.0f, centerX - (0.5f * width), centerY, centerX, centerY + (0.5f * height));
    drawLine(1.0f, 0.0f, 0.0f, centerX, centerY + (0.5f * height), centerX + (0.5f * width), centerY);
    drawLine(1.0f, 0.0f, 0.0f, centerX + (0.5f * width), centerY, centerX - (0.5f * width), centerY);

    // Walls
    drawLine(0.0f, 0.0f, 1.0f, centerX - (0.5f * width), centerY - (0.5f * height), centerX + (0.5f * width), centerY - (0.5f * height));
    drawLine(0.0f, 0.0f, 1.0f, centerX + (0.5f * width), centerY - (0.5f * height), centerX + (0.5f * width), centerY);
    drawLine(0.0f, 0.0f, 1.0f, centerX + (0.5f * width), centerY, centerX - (0.5f * width), centerY);
    drawLine(0.0f, 0.0f, 1.0f, centerX - (0.5f * width), centerY, centerX - (0.5f * width), centerY - (0.5f * height));

    // Door
    drawLine(0.54f, 0.27f, 0.07f, centerX - (0.1f * width), centerY - (0.5f * height), centerX + (0.1f * width), centerY - (0.5f * height));
    drawLine(0.54f, 0.27f, 0.07f, centerX + (0.1f * width), centerY - (0.5f * height), centerX + (0.1f * width), centerY - (0.2f * height));
    drawLine(0.54f, 0.27f, 0.07f, centerX + (0.1f * width), centerY - (0.2f * height), centerX - (0.1f * width), centerY - (0.2f * height));
    drawLine(0.54f, 0.27f, 0.07f, centerX - (0.1f * width), centerY - (0.2f * height), centerX - (0.1f * width), centerY - (0.5f * height));
}
