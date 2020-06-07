#include<glut.h>
#include<gl/GL.h>
#include<iostream>
#include<cmath>
using namespace std;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

/*
    画点
*/
void setPixel(int x, int y)
{
    glColor3f(0.0, 0.0, 1.0);       // 蓝色
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

/*
    椭圆4路对称
*/
void Ellipsepot(int x0, int y0, int x, int y)
{

    setPixel((x0 + x), (y0 + y));
    setPixel((x0 + x), (y0 - y));
    setPixel((x0 - x), (y0 - y));
    setPixel((x0 - x), (y0 + y));
}

/*
    中点画椭圆算法
*/
void MidPoint_Ellipse(int x0, int y0, int a, int b)
{
    double sqa = a * a;
    double sqb = b * b;

    double d = sqb + sqa * (0.25 - b);
    int x = 0;
    int y = b;
    Ellipsepot(x0, y0, x, y);
    // 1
    while (sqb * (x + 1) < sqa * (y - 0.5))
    {
        if (d < 0)
        {
            d += sqb * (2 * x + 3);
        }
        else
        {
            d += (sqb * (2 * x + 3) + sqa * ((-2) * y + 2));
            --y;
        }
        ++x;
        Ellipsepot(x0, y0, x, y);
    }
    d = (b * (x + 0.5)) * 2 + (a * (y - 1)) * 2 - (a * b) * 2;
    // 2
    while (y > 0)
    {
        if (d < 0)
        {
            d += sqb * (2 * x + 2) + sqa * ((-2) * y + 3);
            ++x;
        }
        else
        {
            d += sqa * ((-2) * y + 3);
        }
        --y;
        Ellipsepot(x0, y0, x, y);
    }
}

// 窗口大小改变时调用的登记函数
void ChangeSize(GLsizei w, GLsizei h)
{

    if (h == 0)     h = 1;

    // 设置视区尺寸
    glViewport(0, 0, w, h);

    // 重置坐标系统
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // 建立修剪空间的范围
    if (w <= h)
        glOrtho(0.0f, 250.0f, 0.0f, 250.0f * h / w, 1.0, -1.0);
    else
        glOrtho(0.0f, 250.0f * w / h, 0.0f, 250.0f, 1.0, -1.0);

}

void display(void)
{
    // 用当前背景色填充窗口，如果不写这句会残留之前的图像
    glClear(GL_COLOR_BUFFER_BIT);

    int x0 = 120, y0 = 100, a = 100, b = 60;
    MidPoint_Ellipse(x0, y0, a, b);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("椭圆形");
    glutDisplayFunc(display);
    glutReshapeFunc(ChangeSize);
    init();
    glutMainLoop();
    return 0;
}