#include"Node.h"

//题目描述：删除链表中间的某一个元素，但是不能访问链表的头指针，参数只有要删除的节点指针
//解法描述：要node节点和下一个节点的值进行交换


void deleteNode(ListNode *node)
{
	if (!node || !node->next)
		return;

	int t = node->next->val;//交换node节点和下一个节点的值
	node->next->val = node->val;
	node->val = t;

	node->next = node->next->next;
}