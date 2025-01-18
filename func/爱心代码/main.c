#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#incl
ude <graphics.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>
#include<stdbool.h>
//������һ�����һ����ɫ����
struct Point {
    double x, y;
    COLORREF color;
};
COLORREF colors[7] = { RGB(255,32,83),RGB(252,222,250), RGB(255,0,0), RGB(255,0,0), RGB(255,2,2), RGB(255,0,8),  RGB(255,5,5) };//������һ����ɫ
const int xScreen = 1200;//��������Ļ�Ŀ��
const int yScreen = 800;//��������Ļ�ĸ߶�
const double PI = 3.1426535159;//�����˳�����
const double e = 2.71828;//��������Ȼ����e
const double averag_distance = 0.162;//������һ��ƽ������
const int quantity = 506;//�����˵������
const int circles = 210;//������Բ������
const int frames = 20;//������֡��
//�����˵��ͼ�������
Point origin_points[quantity];
Point points[circles * quantity];
IMAGE images[frames];

//�����˽���Ļ����ת����ͼ������ĺ���
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

//������һ������������ĺ���
int creat_random(int x1, int x2)
{
    if (x2 > x1)
        return rand() % (x2 - x1 + 1) + x1;
}

//������������������ݵĺ���
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

    for (int frame = 0; frame < frames; ++frame)//������һ��ѭ������������ÿһ֡��ͼ��
    {
        images[frame] = IMAGE(xScreen, yScreen);//������һ���µ�ͼ��
        SetWorkingImage(&images[frame]);//����ǰ����ͼ������Ϊ�´�����ͼ��

        for (index = 0; index < points_size; ++index)//������һ��ѭ�������ڻ���ÿһ֡��ͼ��
        {
            double x = points[index].x, y = points[index].y;//��ȡ�������
            double distance = sqrt(pow(x, 2) + pow(y, 2));//����㵽ԭ��ľ���
            double diatance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;//�������ƶ�����
            double x_increase = diatance_increase * x / distance / frames;//������x�᷽����ƶ�����
            double y_increase = diatance_increase * y / distance / frames;//������y�᷽����ƶ�����
            points[index].x += x_increase;
            points[index].y += y_increase;//���µ��λ��
            setfillcolor(points[index].color);//���������ɫ
            solidcircle(screen_x(points[index].x), screen_y(points[index].y), 1);//����һ���뾶Ϊ1��ʵ��Բ

        }

        for (double size = 17; size < 23; size += 0.3)//������һ��ѭ�����������ɲ�ͬ��С��Բ
        {
            for (index = 0; index < quantity; ++index)//������һ��ѭ�����������ɲ�ͬ������Բ
            {
                if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))//�����ж��Ƿ���Ҫ����һ��Բ
                {
                    double x, y;//������Բ�ĵ�����
                    if (size >= 20)
                    {
                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);//����Բ�ĵ�x����
                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);//����Բ�ĵ�y����
                    }
                    else
                    {
                        x = origin_points[index].x * size + creat_random(-5, 5);
                        y = origin_points[index].y * size + creat_random(-5, 5);
                    }

                    setfillcolor(colors[creat_random(0, 6)]);
                    solidcircle(screen_x(x), screen_y(y), 1);//���ư뾶Ϊ1��ʵ��Բ��Բ��λ����x��yȷ��
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