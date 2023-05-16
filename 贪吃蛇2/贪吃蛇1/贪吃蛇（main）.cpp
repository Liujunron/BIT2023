#include<iostream>
#include"ListNode.h"
#include"Manage.h"
#include"Snake.h"
//#include<easyx.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define frame_width1 21
#define frame_height1 21

int dir = 2;
char restart = 'Z';
int V=500;
int T = 0;

//先生成蛇，再生成食物

int main()
{
	//initgraph(800, 600, SHOWCONSOLE);
	//system("pause");

	int mode;
	cout << "请输入您希望的难度：" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1://简单 3食物 1（+0）障碍 v = v-score 
	{
		Snake* s = new Snake;
		s->EnQueue(10, 10);
		Manage* m1 = new Manage;
		/*tag:*/
		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_food(s);
		m1->new_food(s);
		m1->new_food(s);
		m1->print_map();
		//	m1->map[10][11]='$';

		while (true)
		{
			T = V - 20 * score;
			Sleep(T);
			system("cls");
			m1->move_snake(s, score, dir, restart);

			m1->print_map();
		}
	}break;

	case 2://中等 2食物 2（+1/2score）障碍 v = v-2score 
	{
		Snake* s = new Snake;
		s->EnQueue(10, 10);
		Manage* m1 = new Manage;
		/*tag:*/
		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_obstacle1(s);
		m1->new_food(s);
		m1->new_food(s);
		m1->print_map();
		//	m1->map[10][11]='$';

		while (true)
		{
			T = V - 20 * score;
			Sleep(T);
			system("cls");
			m1->move_snake(s, score, dir, restart);

			m1->print_map();
		}
	}break;

	case 3://中等 1食物 2（+1/1score）障碍 v = v-4score 
	{
		Snake* s = new Snake;
		s->EnQueue(10, 10);
		Manage* m1 = new Manage;
		/*tag:*/
		int score = 0;
		m1->new_map();
		m1->new_obstacle1(s);
		m1->new_food(s);
		m1->print_map();
		//	m1->map[10][11]='$';

		while (true)
		{
			T = V - 20 * score;
			Sleep(T);
			system("cls");
			m1->move_snake(s, score, dir, restart);

			m1->print_map();
		}
	}break;

	}


	Snake* s=new Snake;
	s->EnQueue(10, 10);
	Manage* m1=new Manage;
	/*tag:*/
	int score = 0;
	m1->new_map();
	m1->new_obstacle1(s);
	m1->new_food(s);
	m1->new_food(s);
	m1->print_map();
//	m1->map[10][11]='$';

	while (true)
	{
		T = V - 20 * score;
		Sleep(T);
		system("cls");
		m1->move_snake(s,score,dir,restart);
		
		m1->print_map();
	}


	return 0;
}


















/*if (restart == 'Y')
		{
			delete s;
			delete m1;
			s = new Snake;
			s->EnQueue(10, 10);
			m1 = new Manage;
			goto tag;

		}*/
		//Sleep(500);