#include"Node.h"

//��Ŀ����������һ�������ҵ�������n���ڵ�
//�ⷨ��������������ȣ�����

ListNode *nthToLast(ListNode *head, int n)
{
	int length = 0;
	ListNode* p = head;
	while (p)//���������
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