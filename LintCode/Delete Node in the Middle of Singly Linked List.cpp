#include"Node.h"

//��Ŀ������ɾ�������м��ĳһ��Ԫ�أ����ǲ��ܷ��������ͷָ�룬����ֻ��Ҫɾ���Ľڵ�ָ��
//�ⷨ������Ҫnode�ڵ����һ���ڵ��ֵ���н���


void deleteNode(ListNode *node)
{
	if (!node || !node->next)
		return;

	int t = node->next->val;//����node�ڵ����һ���ڵ��ֵ
	node->next->val = node->val;
	node->val = t;

	node->next = node->next->next;
}