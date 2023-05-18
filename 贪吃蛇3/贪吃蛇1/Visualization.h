#pragma once
#include<iostream>
#include"ListNode.h"
#include"Manage.h"
#include"Snake.h"
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#define frame_width1 21
#define frame_height1 21
#define WIDTH 1040
#define HEIGHT 840
#define BATTLE_FIELD_LENGTH 840
#include"Manage.h"
class Visualization
{
public:
	void button(int x, int y, int w, int h, const char* text);
	//插入按钮，直接使用
	void picture(const char* text);
	void picture(int x, int y, int w, int h, const char* text);
	//插入图片，直接使用
	void Visualize(Manage* m);

};

