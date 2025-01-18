#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#incl
ude <graphics.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>
#include<stdbool.h>
//定义了一个点和一个颜色属性
struct Point {
    double x, y;
    COLORREF color;
};
COLORREF colors[7] = { RGB(255,32,83),RGB(252,222,250), RGB(255,0,0), RGB(255,0,0), RGB(255,2,2), RGB(255,0,8),  RGB(255,5,5) };//定义了一组颜色
const int xScreen = 1200;//定义了屏幕的宽度
const int yScreen = 800;//定义了屏幕的高度
const double PI = 3.1426535159;//定义了常数π
const double e = 2.71828;//定义了自然对数e
const double averag_distance = 0.162;//定义了一个平均距离
const int quantity = 506;//定义了点的数量
const int circles = 210;//定义了圆的数量
const int frames = 20;//定义了帧数
//定义了点和图像的数组
Point origin_points[quantity];
Point points[circles * quantity];
IMAGE images[frames];

//定义了将屏幕坐标转换到图形坐标的函数
double screen_x(double x)
{
    x += xScreen / 2;
    return x;
}


double screen_y(double y)
{
    y = -y + yScreen / 2;
    return y;
}

//定义了一个生成随机数的函数
int creat_random(int x1, int x2)
{
    if (x2 > x1)
        return rand() % (x2 - x1 + 1) + x1;
}

//定义了生成随机点数据的函数
void creat_data()
{
    int index = 0;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005)
    {
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance > averag_distance)
        {
            x1 = x2, y1 = y2;
            origin_points[index].x = x2;
            origin_points[index++].y = y2;
        }
    }


    index = 0;
    for (double size = 0.1, lightness = 1.5; size <= 20; size += 0.1)
    {
        double success_p = 1 / (1 + pow(e, 8 - size / 2));
        if (lightness > 1)lightness -= 0.0025;

        for (int i = 0; i < quantity; ++i)
        {
            if (success_p > creat_random(0, 100) / 100.0)
            {
                points[index].color = colors[creat_random(0, 6)];
                points[index].x = size * origin_points[i].x + creat_random(-4, 4);
                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
            }
        }
    }

    int points_size = index;

    for (int frame = 0; frame < frames; ++frame)//定义了一个循环，用于生成每一帧的图像
    {
        images[frame] = IMAGE(xScreen, yScreen);//创建了一个新的图像
        SetWorkingImage(&images[frame]);//将当前工作图像设置为新创建的图像

        for (index = 0; index < points_size; ++index)//定义了一个循环，用于绘制每一帧的图像
        {
            double x = points[index].x, y = points[index].y;//获取点的坐标
            double distance = sqrt(pow(x, 2) + pow(y, 2));//计算点到原点的距离
            double diatance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;//计算点的移动距离
            double x_increase = diatance_increase * x / distance / frames;//计算点的x轴方向的移动距离
            double y_increase = diatance_increase * y / distance / frames;//计算点的y轴方向的移动距离
            points[index].x += x_increase;
            points[index].y += y_increase;//更新点的位置
            setfillcolor(points[index].color);//设置填充颜色
            solidcircle(screen_x(points[index].x), screen_y(points[index].y), 1);//绘制一个半径为1的实心圆

        }

        for (double size = 17; size < 23; size += 0.3)//定义了一个循环，用于生成不同大小的圆
        {
            for (index = 0; index < quantity; ++index)//定义了一个循环，用于生成不同数量的圆
            {
                if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))//用于判断是否需要生成一个圆
                {
                    double x, y;//定义了圆心的坐标
                    if (size >= 20)
                    {
                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);//计算圆心的x坐标
                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);//计算圆心的y坐标
                    }
                    else
                    {
                        x = origin_points[index].x * size + creat_random(-5, 5);
                        y = origin_points[index].y * size + creat_random(-5, 5);
                    }

                    setfillcolor(colors[creat_random(0, 6)]);
                    solidcircle(screen_x(x), screen_y(y), 1);//绘制半径为1的实心圆，圆心位置由x和y确定
                }


                for (double size = 17; size < 23; size += 0.3)
                {
                    for (index = 0; index < quantity; ++index)
                    {
                        if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
                        {
                            double x, y;
                            if (size >= 20)
                            {
                                x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                                y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                            }
                            else
                            {
                                x = origin_points[index].x * size + creat_random(-5, 5);
                                y = origin_points[index].y * size + creat_random(-5, 5);
                            }
                            setfillcolor(colors[creat_random(0, 6)]);
                            solidcircle(screen_x(x), screen_y(y), 1);
                        }
                    }
                }
            }
        }
    }
}


int main()
{
    initgraph(xScreen, yScreen);
    BeginBatchDraw();
    srand(time(0));
    creat_data();
    SetWorkingImage();
    bool extend = true, shrink = false;
    for (int frame = 0; !_kbhit();)
    {
        putimage(0, 0, &images[frame]);
        FlushBatchDraw();
        Sleep(20);
        cleardevice();
        if (extend)
            frame == 19 ? (shrink = true, extend = false) : ++frame;
        else
            frame == 0 ? (shrink = false, extend = true) : --frame;

    }
    EndBatchDraw();
    closegraph();
    return 0;
}