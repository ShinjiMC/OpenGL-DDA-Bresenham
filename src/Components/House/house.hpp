#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Components/DDA/dda.hpp"
#include "Components/Bresenham/bresenham.hpp"

class House
{
private:
    float centerX, centerY;
    std::string lineType, technique;
    float width, height;
    void drawLine(float r, float g, float b, float x1, float y1, float x2, float y2);

public:
    House(float cx, float cy, float width, float height, std::string lineType, std::string technique);
    void draw();
};

#endif // HOUSE_HPP
