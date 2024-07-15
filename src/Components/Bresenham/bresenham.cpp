#include "bresenham.hpp"

Bresenham::Bresenham(float r, float g, float b, float x1, float y1, float x2, float y2, std::string style)
    : red(r), green(g), blue(b), x_start(x1), y_start(y1), x_end(x2), y_end(y2), line_style(style) {}

void Bresenham::drawPoint(int x, int y, bool visible)
{
    if (visible)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
}

void Bresenham::drawLine()
{
    glColor3f(red, green, blue);

    int x1 = static_cast<int>(x_start);
    int y1 = static_cast<int>(y_start);
    int x2 = static_cast<int>(x_end);
    int y2 = static_cast<int>(y_end);
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = (x2 < x1) ? -1 : 1;
    incy = (y2 < y1) ? -1 : 1;
    x = x1;
    y = y1;

    int patternIndex = 0;
    int patternLength = 1;
    bool pattern[] = {true}; // Solid line as default

    if (line_style == "dashed")
    {
        bool tempPattern[] = {true, true, true, true, false, false, false, false};
        patternLength = sizeof(tempPattern) / sizeof(tempPattern[0]);
        std::copy(tempPattern, tempPattern + patternLength, pattern);
    }
    else if (line_style == "dotted")
    {
        bool tempPattern[] = {true, false};
        patternLength = sizeof(tempPattern) / sizeof(tempPattern[0]);
        std::copy(tempPattern, tempPattern + patternLength, pattern);
    }

    if (dx > dy)
    {
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            drawPoint(x, y, pattern[patternIndex]);
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            patternIndex = (patternIndex + 1) % patternLength;
        }
    }
    else
    {
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            drawPoint(x, y, pattern[patternIndex]);
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            patternIndex = (patternIndex + 1) % patternLength;
        }
    }

    // Draw the last point
    drawPoint(x, y, pattern[patternIndex]);
}

void Bresenham::printPoints()
{
    int x1 = static_cast<int>(x_start);
    int y1 = static_cast<int>(y_start);
    int x2 = static_cast<int>(x_end);
    int y2 = static_cast<int>(y_end);
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = (x2 < x1) ? -1 : 1;
    incy = (y2 < y1) ? -1 : 1;
    x = x1;
    y = y1;
    std::cout << "Bresenham: (" << x_start << ", " << y_start << ") -> (" << x_end << ", " << y_end << ")" << std::endl;
    if (dx > dy)
    {
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            std::cout << "Point: (" << x << ", " << y << "), Error: " << e << std::endl;
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
        }
    }
    else
    {
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            std::cout << "Point: (" << x << ", " << y << "), Error: " << e << std::endl;
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
        }
    }

    // Print the last point
    std::cout << "Point: (" << x << ", " << y << "), Error: " << e << std::endl;
}