#ifndef BRESENHAM_HPP
#define BRESENHAM_HPP

#include <GL/glut.h>
#include <string>
#include <iostream>

class Bresenham
{
private:
    float red, green, blue;
    float x_start, y_start, x_end, y_end;
    std::string line_style;

public:
    Bresenham(float r, float g, float b, float x1, float y1, float x2, float y2, std::string style);
    void drawPoint(int x, int y, bool visible);
    void drawLine();    // Método para dibujar la línea
    void printPoints(); // Método para imprimir los puntos de la línea
};

#endif // BRESENHAM_HPP
