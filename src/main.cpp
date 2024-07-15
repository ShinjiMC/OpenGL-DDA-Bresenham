#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "Components/DDA/dda.hpp"
#include "Components/Bresenham/bresenham.hpp"
#include "Components/House/house.hpp"
#include "Components/Car/car.hpp"

void testDDA()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float centerY = 0.0f;

    DDA line1(1.0, 0.0, 0.0, -450.0, centerY + 200.0, 450.0, centerY + 210.0, "solid");
    DDA line2(0.0, 1.0, 0.0, -450.0, centerY + 150.0, 450.0, centerY + 160.0, "solid");
    DDA line3(0.0, 0.0, 1.0, -450.0, centerY + 100.0, 450.0, centerY + 110.0, "solid");
    DDA line4(1.0, 0.0, 0.0, -450.0, centerY + 50.0, 450.0, centerY + 60.0, "dashed");
    DDA line5(0.0, 1.0, 0.0, -450.0, centerY + 0.0, 450.0, centerY + 10.0, "dashed");
    DDA line6(0.0, 0.0, 1.0, -450.0, centerY - 50.0, 450.0, centerY - 40.0, "dashed");
    DDA line7(1.0, 0.0, 0.0, -450.0, centerY - 100.0, 450.0, centerY - 90.0, "dotted");
    DDA line8(0.0, 1.0, 0.0, -450.0, centerY - 150.0, 450.0, centerY - 140.0, "dotted");
    DDA line9(0.0, 0.0, 1.0, -450.0, centerY - 200.0, 450.0, centerY - 190.0, "dotted");

    line1.drawLine();
    line2.drawLine();
    line3.drawLine();
    line4.drawLine();
    line5.drawLine();
    line6.drawLine();
    line7.drawLine();
    line8.drawLine();
    line9.drawLine();

    glFlush();
}

void testBresenham()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float centerY = 0.0f;

    Bresenham line1(1.0, 0.0, 0.0, -450.0, centerY + 200.0, 450.0, centerY + 190.0, "solid");
    Bresenham line2(0.0, 1.0, 0.0, -450.0, centerY + 150.0, 450.0, centerY + 140.0, "solid");
    Bresenham line3(0.0, 0.0, 1.0, -450.0, centerY + 100.0, 450.0, centerY + 90.0, "solid");
    Bresenham line4(1.0, 0.0, 0.0, -450.0, centerY + 50.0, 450.0, centerY + 40.0, "dashed");
    Bresenham line5(0.0, 1.0, 0.0, -450.0, centerY + 0.0, 450.0, centerY - 10.0, "dashed");
    Bresenham line6(0.0, 0.0, 1.0, -450.0, centerY - 50.0, 450.0, centerY - 60.0, "dashed");
    Bresenham line7(1.0, 0.0, 0.0, -450.0, centerY - 100.0, 450.0, centerY - 110.0, "dotted");
    Bresenham line8(0.0, 1.0, 0.0, -450.0, centerY - 150.0, 450.0, centerY - 160.0, "dotted");
    Bresenham line9(0.0, 0.0, 1.0, -450.0, centerY - 200.0, 450.0, centerY - 210.0, "dotted");

    line1.drawLine();
    line2.drawLine();
    line3.drawLine();
    line4.drawLine();
    line5.drawLine();
    line6.drawLine();
    line7.drawLine();
    line8.drawLine();
    line9.drawLine();

    glFlush();
}

void testComparison()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Bresenham line1(1.0, 0.0, 0.0, 2.0, 2.0, 10.0, 5.0, "solid");
    DDA line2(1.0, 0.0, 0.0, 2.0, 2.0, 10.0, 5.0, "solid");
    line1.printPoints();
    line2.printPoints();
    glFlush();
}

float g_x, g_y;
int g_width, g_height;
std::string g_lineStyle, g_drawStyle;
void showQuadrants()
{
    DDA lineX(1.0, 1.0, 1.0, -1000.0, 0.0, 1000.0, 0.0, "solid");
    DDA lineY(1.0, 1.0, 1.0, 0.0, -1000.0, 0.0, 1000.0, "solid");

    lineX.drawLine();
    lineY.drawLine();
}

void showHouse()
{
    glClear(GL_COLOR_BUFFER_BIT);
    showQuadrants();
    House house(g_x, g_y, g_width, g_height, g_lineStyle, g_drawStyle);
    house.draw();
    glFlush();
}

void showCar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    showQuadrants();
    Car car(g_x, g_y, g_width, g_height, g_lineStyle, g_drawStyle);
    car.draw();
    glFlush();
}

bool isNumber(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c)
                                      { return !std::isdigit(c) && c != '.' && c != '-'; }) == s.end();
}
void initGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 0.0, 0.0, 0.0);
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <testDDA|testBresenham|compare|house|car> [additional parameters]" << std::endl;
        return -1;
    }

    std::string command = argv[1];

    if (command == "house" || command == "car")
    {
        g_x = (argc > 2 && isNumber(argv[2])) ? std::stof(argv[2]) : 0.0f;
        g_y = (argc > 3 && isNumber(argv[3])) ? std::stof(argv[3]) : 0.0f;
        g_width = (argc > 4 && isNumber(argv[4])) ? std::abs(std::stoi(argv[4])) : 200;
        g_height = (argc > 5 && isNumber(argv[5])) ? std::abs(std::stoi(argv[5])) : 200;
        g_lineStyle = (argc > 6 && (std::string(argv[6]) == "solid" || std::string(argv[6]) == "dashed" || std::string(argv[6]) == "dotted")) ? argv[6] : "solid";
        g_drawStyle = (argc > 7 && (std::string(argv[7]) == "DDA" || std::string(argv[7]) == "Bresenham")) ? argv[7] : "DDA";

        glutInitWindowSize(g_width + 50, g_height + 50);
        glutInitWindowPosition(100, 100);

        if (command == "house")
        {
            glutCreateWindow("Drawing House");
            initGL();
            glutDisplayFunc(showHouse);
        }
        else if (command == "car")
        {
            glutCreateWindow("Drawing Car");
            initGL();
            glutDisplayFunc(showCar);
        }
    }
    else
    {
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100, 100);

        if (command == "testDDA")
        {
            glutCreateWindow("Testing DDA");
            initGL();
            glutDisplayFunc(testDDA);
        }
        else if (command == "testBresenham")
        {
            glutCreateWindow("Testing Bresenham");
            initGL();
            glutDisplayFunc(testBresenham);
        }
        else if (command == "compare")
        {
            glutCreateWindow("Comparison DDA vs Bresenham");
            glutDisplayFunc(testComparison);
        }
        else
        {
            std::cerr << "Invalid command: " << command << std::endl;
            return -1;
        }
    }

    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
