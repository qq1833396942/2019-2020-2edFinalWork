// Bounce.cpp
// Demonstrates a simple animated rectangle program with GLUT
//用GLUT演示一个简单的动画矩形程序
// OpenGL SuperBible, 3rd Edition

#include <glut.h>	// OpenGL toolkit
#include<gl/GL.h>
#include<gl/GLU.h>


// 初始化矩形位置和大小
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 25;

// x和y方向上的步长
// (每次移动的像素)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// 跟随窗口改变长宽
GLfloat windowWidth;
GLfloat windowHeight;

///////////////////////////////////////////////////////////
// 绘画场景
void RenderScene(void)
{
    // 使用当前的清除颜色清除窗口
    glClear(GL_COLOR_BUFFER_BIT);

    // 设置小方块颜色为红色
    glColor3f(1.0f, 0.0f, 0.0f);

    // 用当前颜色绘制一个填充的矩形
    glRectf(x, y, x + rsize, y - rsize);

    // Flush drawing commands and swap
    //刷新绘图命令并交换
    glutSwapBuffers();
}

///////////////////////////////////////////////////////////
// 空闲时由GLUT库调用（不调整窗口大小或移动窗口）
void TimerFunction(int value)
{
    // Reverse direction when you reach left or right edge
    //到达左边缘或右边缘时方向相反--用于反弹效果
    if (x > windowWidth - rsize || x < -windowWidth)
        xstep = -xstep;

    // Reverse direction when you reach top or bottom edge
    //到达上边缘或下边缘时方向相反--用于反弹效果
    if (y > windowHeight || y < -windowHeight + rsize)
        ystep = -ystep;

    // Actually move the square
    //移动矩形
    x += xstep;
    y += ystep;

    // Check bounds. This is in case the window is made
    // smaller while the rectangle is bouncing and the 
    // rectangle suddenly finds itself outside the new
    // clipping volume
    //检查边界，这是在窗口被建立的更小
    //当长方形在弹跳并且长方形忽然发现他跑到了新剪裁量外
    if (x > (windowWidth - rsize + xstep))
        x = windowWidth - rsize - 1;
    else if (x < -(windowWidth + xstep))
        x = -windowWidth - 1;

    if (y > (windowHeight + ystep))
        y = windowHeight - 1;
    else if (y < -(windowHeight - rsize + ystep))
        y = -windowHeight + rsize - 1;

    // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1);    //需要在函数中再调用一次，才能保证循环
}

///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
    // Set clear color to blue
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
//修改窗口大小
void ChangeSize(int w, int h)
{
    GLfloat aspectRatio;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    //将视口设置为窗口尺寸
    glViewport(0, 0, w, h);

    // Reset coordinate system
    //重置坐标系
    glMatrixMode(GL_PROJECTION);    //GL_PROJECTION--投影模式
    glLoadIdentity();      //将当前点移到了屏幕中心：类似于一个复位操作

    // Establish clipping volume (left, right, bottom, top, near, far)
    aspectRatio = (GLfloat)w / (GLfloat)h;

    //glOrtho(left, right, bottom, top, near, far)
    //left表示视景体左面的坐标, right表示右面的坐标, bottom表示下面的, top表示上面的
    if (w <= h)
    {
        windowWidth = 100;
        windowHeight = 100 / aspectRatio;
        glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
    }
    else
    {
        windowWidth = 100 * aspectRatio;
        windowHeight = 100;
        glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bounce");
    glutDisplayFunc(RenderScene);   //设置绘画场景
    glutReshapeFunc(ChangeSize);    //窗口大小改变时调用
    glutTimerFunc(33, TimerFunction, 1);    //定时器，33毫秒，回调函数指针TimerFunction,区别值

    SetupRC();  //Set clear color to blue

    glutMainLoop();     // 让主事件无限循环

    return 0;
}
