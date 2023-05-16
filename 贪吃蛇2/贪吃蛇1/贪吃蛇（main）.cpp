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

//先生成蛇，再生成食物

int main()
{
	
	//initgraph(800, 600, SHOWCONSOLE);
	//system("pause");
	Snake* s=new Snake;
	s->EnQueue(10, 10);
	Manage* m1=new Manage;
	int score = 0;
	m1->new_map();
	m1->new_obstacle1(s);
	m1->new_food(s);
	m1->print_map();
	m1->map[10][11]='$';
	cout << "song is so handsome" << endl;

	while (true)
	{
		Sleep(500);
		system("cls");
		m1->move_snake(s,score,dir);
		//Sleep(500);
		m1->print_map();
	}


	return 0;
}