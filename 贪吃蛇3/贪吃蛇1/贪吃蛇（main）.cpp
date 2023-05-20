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

//����������yhr
//hey bro

int dir = 2;//��¼��ǰ����״̬�ı���
//���涨����Ϊ1������Ϊ2������Ϊ3������Ϊ4
int restart = 0;
int T = 0;
int X = 0;//�������ٵİ������
int Y = 0;//�����ϰ������ɵİ������
int mode = 0;

char ss[10];
char t[17] = "����������������";
char name[10];

int main()
{
	Visualization* v = new Visualization;
	initgraph(WIDTH, HEIGHT , EX_SHOWCONSOLE);
	v->picture(0,0,WIDTH,HEIGHT,"./startpicture.jpg");
	mciSendString("open game.mp3", 0, 0, 0);
	mciSendString("play game.mp3 repeat", 0, 0, 0);
	v->button(WIDTH / 2 - 100, HEIGHT / 3, 200, 50, "��ʼ��Ϸ");
//	v->button(WIDTH / 2 - 100, HEIGHT / 2, 200, 50, "���а�");
	v->button(WIDTH / 2 - 100, 2 * HEIGHT / 3, 200, 50, "�˳���Ϸ");
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
					v->button(WIDTH / 2 - 100, 100, 200, 50, "��ѡ���Ѷ�");
					v->button(WIDTH / 2 - 100, HEIGHT / 3, 200, 50, "����");
					v->button(WIDTH / 2 - 100, HEIGHT / 2, 200, 50, "�м�");
					v->button(WIDTH / 2 - 100, 2 * HEIGHT / 3, 200, 50, "�߼�");
					while (true)
					{
						if (peekmessage(&msg, EM_MOUSE))
						{
							switch (msg.message)
							{
							case WM_LBUTTONDOWN:
								if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 3 && msg.y <= HEIGHT / 3 + 50)
								{
									//����
									mode = 1;
									BeginBatchDraw();
									cleardevice();
									goto tag;
								}
								else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= HEIGHT / 2 && msg.y <= HEIGHT / 2 + 50)
								{
									//�м�
									mode = 2;
									BeginBatchDraw();
									cleardevice();
									goto tag;
								}
								else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 - 100 + 200 && msg.y >= 2 * HEIGHT / 3 && msg.y <= 2 * HEIGHT / 3 + 50)
								{
									//�߼�
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
					//�������а�
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
	case 1://�� 3ʳ�� 1��+0���ϰ� v = v-score 
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
			v->button(900, HEIGHT / 2, 100, 100, num);//��ӡ����
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "��ϲ�������ĵ÷�Ϊ");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "�˳���Ϸ");
				goto end;
			}
			BeginBatchDraw();
			cleardevice();
			v->picture(0, 0, BATTLE_FIELD_LENGTH, BATTLE_FIELD_LENGTH, "./battle_background.png");
		}
	}break;

	case 2://�е� 2ʳ�� 2��+1/2score���ϰ� v = v-2score 
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
			v->button(900, HEIGHT / 2, 100, 100, num);//��ӡ����
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "��ϲ�������ĵ÷�Ϊ");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "�˳���Ϸ");
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

	case 3://�е� 1ʳ�� 2��+1/1score���ϰ� v = v-4score 
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
			v->button(900, HEIGHT / 2, 100, 100, num);//��ӡ����
			Sleep(T);
			m1->move_snake(s, score, dir, restart);
			if (restart == 1)
			{
				sprintf(ss, "%d", score);
				InputBox(name, 10, t);
				v->button(WIDTH / 2 - 200, HEIGHT / 3, 400, 50, "��ϲ�������ĵ÷�Ϊ");
				v->button(WIDTH / 2 - 200, HEIGHT / 2, 400, 50, ss);
				v->button(WIDTH / 2 - 200, 2 * HEIGHT / 3, 400, 50, "�˳���Ϸ");
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