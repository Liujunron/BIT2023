#pragma once
#include<iostream>
class ListNode//½áµã
{
	friend class Snake;
	friend class Manage;
	int x;
	int y;
	ListNode* next;
public:
	ListNode();
	ListNode(int a,int b);
};

