#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include"ListNode.h"
#include"Snake.h"
#include"Manage.h"
#include"Visualization.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
#define frame_width1 21
#define frame_height1 21
#define WIDTH 1040
#define HEIGHT 840
#define BATTLE_FIELD_LENGTH 840

//哈哈，我是yhr
//hey bro

int dir = 2;//记录当前方向状态的变量
//并规定向左为1，向右为2，向上为3，向下为4
int restart = 0;
int T = 0;
int X = 0;//控制蛇速的伴随变量
int Y = 0;//控制障碍物生成的伴随变量
int mode = 0;

char ss[10];
char t[17] = "请输入您的姓名：";
char name[10];

int main()
{
	Visualization* v = new Visualization;
	initgraph(WIDTH, HEIGHT , EX_SHOWCONSOLE);
	v->picture(0,0,WIDTH,HEIGHT,"./startpicture.jpg");
	mciSendString("open game.mp3", 0, 0, 0);
	mciSendString("play game.mp3 repeat", 0, 0, 0);
	v->button(WIDTH / 2 - 100, HEIGHT / 3, 200, 50, "开始游戏");
//	v->button(WIDTH / 2 - 100, HEIGHT / 2, 200, 50, "排行榜");
	v->button(WIDTH / 2 - 100, 2 * HEIGHT / 3, 200, 50, "退出游戏");
	while (true)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 3 && msg.y <= HEIGHT / 3 + 50)
				{
					BeginBatchDraw();
					cleardevice();
					v->picture(0, 0, WIDTH,HEIGHT, "./startpicture.jpg");
					EndBatchDraw();
					v->button(WIDTH / 2 - 100, 100, 200, 50, "请选择难度");
					v->button(WIDTH / 2 - 100, HEIGHT / 3, 200, 50, "初级");
					v->button(WIDTH / 2 - 100, HEIGHT / 2, 200, 50, "中级");
					v->button(WIDTH / 2 - 100, 2 * HEIGHT / 3, 200, 50, "高级");
					while (true)
					{
						if (peekmessage(&msg, EM_MOUSE))
						{
							switch (msg.message)
							{
							case WM_LBUTTONDOWN:
								if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 3 && msg.y <= HEIGHT / 3 + 50)
								{
									//初级
									mode = 1;
									BeginBatchDraw();
									cleardevice();
									goto tag;
								}
								else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 2 && msg.y <= HEIGHT / 2 + 50)
								{
									//中级
									mode = 2;
									BeginBatchDraw();
									cleardevice();
									goto tag;
								}
								else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= 2 * HEIGHT / 3 && msg.y <= 2 * HEIGHT / 3 + 50)
								{
									//高级
									mode = 3;
									BeginBatchDraw();
									cleardevice();
									goto tag;
								}
							}
						}
					}

				}
				else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 2 && msg.y <= HEIGHT / 2 + 50)
				{
					//调出排行榜
				}
				else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= 2 * HEIGHT / 3 && msg.y <= 2 * HEIGHT / 3 + 50)
				{
					mciSendString("close game.mp3", 0, 0, 0);
					exit(0);
				}
			}
		}
	}

tag:
	v->picture(0, 0, BATTLE_FIELD_LENGTH, BATTLE_FIELD_LENGTH, "./battle_background.png");
	EndBatchDraw();
	Snake* s = new Snake;
	s->EnQueue(10, 10);
	Manage* m1 = new Manage;
	char num[2] = "0";
	switch (mode)
	{
	case 1://简单 3食物 1（+0）障碍 v = v-score 
	{

		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_food(s);
		m1->new_food(s);
		m1->new_food(s);
		BeginBatchDraw();
		T = 1000;

		while (true)
		{
			v->Visualize(m1);
			EndBatchDraw();
			if (score - X == 1&&T>=250)
			{
				T = T - score;
				X = X + 1;
			}
			sprintf(num, "%d", score);
			v->button(900, HEIGHT / 2, 100, 100, num);//打印分数
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "恭喜您！您的得分为");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "退出游戏");
				goto end;
			}
			BeginBatchDraw();
			cleardevice();
			v->picture(0, 0, BATTLE_FIELD_LENGTH, BATTLE_FIELD_LENGTH, "./battle_background.png");
		}
	}break;

	case 2://中等 2食物 2（+1/2score）障碍 v = v-2score 
	{
		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_obstacle1(s);
		m1->new_food(s);
		m1->new_food(s);
		BeginBatchDraw();
		T = 800;
		while (true)
		{
			v->Visualize(m1);
			EndBatchDraw();
			if (score - X == 1&&T >= 170)
			{
				T = T - 2 * score;
				X = X + 1;
			}
			sprintf(num, "%d", score);
			v->button(900, HEIGHT / 2, 100, 100, num);//打印分数
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "恭喜您！您的得分为");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "退出游戏");
				goto end;
			}
			BeginBatchDraw();
			cleardevice();
			if (score - Y == 2)
			{
				m1->new_obstacle1(s);
				Y = Y + 2;
			}
			v->picture(0, 0, BATTLE_FIELD_LENGTH, BATTLE_FIELD_LENGTH, "./battle_background.png");
		}
	}break;

	case 3://中等 1食物 2（+1/1score）障碍 v = v-4score 
	{
		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_food(s);
		BeginBatchDraw();
		T = 600;
		while (true)
		{
			v->Visualize(m1);
			EndBatchDraw();
			if (score - X == 1 && T >= 130)
			{
				T = T - 4 * score;
				X = X + 1;
			}
			sprintf(num, "%d", score);
			v->button(900, HEIGHT / 2, 100, 100, num);//打印分数
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "恭喜您！您的得分为");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "退出游戏");
				goto end;
			}
			BeginBatchDraw();
			cleardevice();
			if (score - Y == 1)
			{
				m1->new_obstacle1(s);
				Y = Y + 1;
			}
			v->picture(0, 0, BATTLE_FIELD_LENGTH, BATTLE_FIELD_LENGTH, "./battle_background.png");
		}
	}break;

	}
end:
	while (true)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 200 && msg.x <= WIDTH / 2 - 200 + 400 && msg.y >= 2 * HEIGHT / 3 && msg.y <= 2 * HEIGHT / 3 + 50)
				{
					exit(0);
				}
			}
		}
	}
	system("pause");


	return 0;
}