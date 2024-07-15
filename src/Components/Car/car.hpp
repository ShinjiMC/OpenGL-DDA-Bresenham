#ifndef CAR_HPP
#define CAR_HPP

#include "Components/DDA/dda.hpp"
#include "Components/Bresenham/bresenham.hpp"

class Car
{
private:
    float centerX, centerY;
    std::string lineType, technique;
    int width, height;
    void drawLine(float r, float g, float b, float x1, float y1, float x2, float y2);

public:
    Car(float cx, float cy, int width, int height, std::string lineType, std::string technique);
    void draw();
};

#endif // CAR_HPP
