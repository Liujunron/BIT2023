#pragma once
#include<conio.h>
#include<windows.h>
#include"Snake.h"
#define frame_width 21
#define frame_height 21
class Manage//先入队，判断果实坐标和新入队坐标，依据前面决定地图上尾巴是否删除、出队
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