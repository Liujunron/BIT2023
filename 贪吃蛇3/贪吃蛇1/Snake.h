#pragma once
#include"ListNode.h"
#include"Manage.h"
class Snake
{
	ListNode* head;//ָ��ͷ���
	ListNode* tail;//ָ�����һ�����ݽ��
	int length;
public:
	Snake();
	bool EnQueue(int y,int x);//��� β����
	bool DeQueue();//���� ͷ����
	~Snake();//��
	void Clear();
	bool IsEmpty();

	bool FindNode(int y1,int x1);
	bool FindNode1(int y1, int x1);
	ListNode* GetHead();
	ListNode* GetTail();

	friend class Manage;


};

