#pragma once
#include"ListNode.h"
#include"Manage.h"
class Snake
{
	ListNode* head;//指向头结点
	ListNode* tail;//指向最后一个数据结点
	int length;
public:
	Snake();
	bool EnQueue(int y,int x);//入队 尾上用
	bool DeQueue();//出队 头上用
	~Snake();//死
	void Clear();
	bool IsEmpty();

	bool FindNode(int y1,int x1);
	bool FindNode1(int y1, int x1);
	ListNode* GetHead();
	ListNode* GetTail();

	friend class Manage;


};

