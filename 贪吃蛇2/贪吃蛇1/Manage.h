#pragma once
#include<conio.h>
#include<windows.h>
#include"Snake.h"
#define frame_width 21
#define frame_height 21
class Manage//����ӣ��жϹ�ʵ�������������꣬����ǰ�������ͼ��β���Ƿ�ɾ��������
{
    friend class Snake;
public:
    char map[frame_height][frame_width] = {'0'};
public:
    //void gotoxy(int x, int y);
    void new_map();
    void print_map();
    void new_food(Snake* s);
    bool check_foodinsnake(int a, int b, Snake* s);
    void move_snake(Snake* s, int& score, int&, char&);
    void new_obstacle1(Snake* s);
};