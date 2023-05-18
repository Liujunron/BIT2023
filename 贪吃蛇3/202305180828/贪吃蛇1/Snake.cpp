#include "Snake.h"

Snake::Snake()
{
	head = new ListNode;
	tail = head;
	length = 0;
}

bool Snake::EnQueue(int y, int x)
{
	ListNode* p = new ListNode(y,x);
	tail->next = p;
	tail = p;
	length++;
	return true;
}

bool Snake::DeQueue()
{
	if (IsEmpty()) return false;
	ListNode* p = head->next;
	head->next = head->next->next;
	if (tail == p) tail = head;//注意，如果队里只剩一个元素了...
	delete p;
	p = NULL;
	length--;
	return true;
}

Snake::~Snake()
{
}

void Snake::Clear()
{
	while (DeQueue());
}

bool Snake::IsEmpty()
{
	if (head == tail) return true;
	else return false;
}

bool Snake::FindNode(int y1, int x1)
{
	if (IsEmpty()) return false;
	else
	{
		ListNode* p = head->next;
		for (int i = 0; i < length; i++)
		{
			if (p->x == x1 && p->y == y1)
			{
				p = NULL;
				return true;
			}
			p = p->next;
		}
		p = NULL;
		return false;
	}

}

bool Snake::FindNode1(int y1, int x1)
{
	if (IsEmpty()) return false;
	else
	{
		ListNode* p = head->next;
		for (int i = 0; i < length-1; i++)
		{
			if (p->x == x1 && p->y == y1)
			{
				p = NULL;
				return true;
			}
			p = p->next;
		}
		p = NULL;
		return false;
	}
}

ListNode* Snake::GetHead()
{
	return head;
}

ListNode* Snake::GetTail()
{
	return tail;
}
