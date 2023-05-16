#include "Manage.h"
#include"Snake.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#define frame_width 21
#define frame_height 21
using namespace std;

//void gotoxy(int x, int y)
//{
//    COORD pos;//COORD是一种自带结构体，表示一个字符在控制台屏幕上的坐标
//    HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE); //从标准输出设备里取出一个句柄
//    pos.X = y, pos.Y = x;
//    SetConsoleCursorPosition(han, pos);//定位光标的函数
//}

void Manage:: new_map()
{
    for (int i = 0; i < frame_height; i++)
    {
        for (int j = 0; j < frame_width; j++) 
        map[i][j] = '0';//数字0
    }
    for (int i = 0; i < frame_height; i++)
    {
        map[i][0] ='#';
        map[i][frame_width-1] = '#';
    }
    for (int i = 0; i < frame_width; i++)
    {
        map[0][i] = '#';
        map[frame_height-1][i] = '#';
    }
    map[10][10] = 's';
}


void Manage::print_map()
{
    for (int i = 0; i < frame_height; i++)
    {
        for (int j = 0; j < 21; j++)
            cout << map[i][j];
        cout << endl;
    }
}

void Manage::new_food(Snake *s)
{
    int a=0, b=0;
    srand(time(0));
    while (check_foodinsnake(a,b,s))
    {
        a= rand() % (frame_height - 2) + 1;
        b= rand() % (frame_width - 2) + 1;
    }
    map[a][b] = '$';
}

void Manage::new_obstacle1(Snake *s)
{
    int a = 0, b = 0;
$1: srand(time(0));
    a = rand() % (frame_height - 2) + 1;
    b = rand() % (frame_width - 2) + 1;
    if (a == 10 && b == 10) goto $1;
    map[a][b] = '#';
}

bool Manage::check_foodinsnake(int a,int b, Snake *s)
{
    
    if (map[a][b] != '#' && !s->FindNode(a, b))
        return false;
    else
        return true;
}

void Manage::move_snake(Snake* s,int score, int& dir)
{
    
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = 1;
            break;
        case 'd':
            dir = 2;
            break;
        case 'w':
            dir = 3;
            break;
        case 's':
            dir = 4;
            break;
        case 'x':
            //gameover = true;//暂停功能
            break;
        }
    }
    

    ListNode* p = s->GetTail();
    ListNode* q = s->GetHead();
    switch (dir)
    {
    case 1:
        s->EnQueue(p->y, p->x-1);
        p = s->GetTail();
        if (s->FindNode1(p->y, p->x)||map[p->y][p->x]=='#')
        {
            cout << "gameover"<<endl;
            //main函数中询问重新开始或结束游戏
            cout << "您是否选择重新开始游戏" << endl;
            cout << "        Y         N" << endl;
            char choose;
            cin >> choose;
            if (choose == 'Y')
            {
                //主函数里写goto
            }
            else
            {
                exit(0);
            }
        }
        else if (map[p->y][p->x] == '$')
        {
            score++;
            new_food(s);
        }
        //长按加速功能
  
        else
        {
            map[s->head->next->y][s->head->next->x] = '0';
            s->DeQueue();
        }
        q = q->next;//此时q不再指向头结点（蛇尾前的）
        for (int i = 0; i < s->length; i++,q=q->next)
        {
            map[q->y][q->x] = 's';
        }
        break;
    case 2:
        s->EnQueue(p->y, p->x + 1);
        p = s->GetTail();
        if (s->FindNode1(p->y, p->x) || map[p->y][p->x] == '#')
        {
            cout << "gameover" << endl;
            //main函数中询问重新开始或结束游戏
            cout << "您是否选择重新开始游戏" << endl;
            cout << "        Y         N" << endl;
            char choose;
            cin >> choose;
            if (choose == 'Y')
            {
                //主函数里写goto
            }
            else
            {
                exit(0);
            }
        }
        else if (map[p->y][p->x] == '$')
        {
            score++;
            new_food(s);
        }
        //长按加速功能
        else
        {
            map[s->head->next->y][s->head->next->x] = '0';
            s->DeQueue();
        }
        q = q->next;
        for (int i = 0; i < s->length; i++, q = q->next)
        {
            map[q->y][q->x] = 's';
        }
        break;
    case 3:
        s->EnQueue(p->y-1, p->x);
        p = s->GetTail();
        if (map[p->y][p->x] == '#'|| s->FindNode1(p->y, p->x)
            )
        {
            cout << "gameover" << endl;
            //main函数中询问重新开始或结束游戏
            cout << "您是否选择重新开始游戏" << endl;
            cout << "        Y         N" << endl;
            char choose;
            cin >> choose;
            if (choose == 'Y')
            {
                //主函数里写goto
            }
            else
            {
                exit(0);
            }
        }
        else if (map[p->y][p->x] == '$')
        {
            score++;
            new_food(s);
        }
        //长按加速功能
        else
        {
            map[s->head->next->y][s->head->next->x] = '0';
            s->DeQueue();
        }
        q = q->next;
        for (int i = 0; i < s->length; i++, q = q->next)
        {
            map[q->y][q->x] = 's';
        }
        break;
    case 4:
        s->EnQueue(p->y+1, p->x);
        p = s->GetTail();
        if (s->FindNode1(p->y, p->x) || map[p->y][p->x] == '#')
        {
            cout << "gameover" << endl;
            //main函数中询问重新开始或结束游戏
            cout << "您是否选择重新开始游戏" << endl;
            cout << "        Y         N" << endl;
            char choose;
            cin >> choose;
            if (choose == 'Y')
            {
                //主函数里写goto
            }
            else
            {
                exit(0);
            }
        }
        else if (map[p->y][p->x] == '$')
        {
            score++;
            new_food(s);
        }
        //长按加速功能
        else
        {
            map[s->head->next->y][s->head->next->x] = '0';
            s->DeQueue();
        }
        q = q->next;
        for (int i = 0; i < s->length; i++, q = q->next)
        {
            map[q->y][q->x] = 's';
        }
        break;
    default:
        break;
    }
}