#include"Node.h"

//题目描述：给定一个链表，找到倒数第n个节点
//解法描述：求出链表长度，再找

ListNode *nthToLast(ListNode *head, int n)
{
	int length = 0;
	ListNode* p = head;
	while (p)//求出链表长度
	{
		++length;
		p = p->next;
	}

	int count = length - n;
	while (count)
	{
		head = head->next;
		--count;
	}

	return head;
}