#include"Node.h"

//��Ŀ��������ɶ������Ĳ������
//�ⷨ������prevָ�򸸽ڵ㣬curָ��ǰ�ڵ㣬����½�

TreeNode* insertNode(TreeNode* root, TreeNode* node)
{
	TreeNode* prev = nullptr, *cur = root;
	while (cur)
	{
		prev = cur;
		if (cur->val < node->val)
			cur = cur->right;
		else if (cur->val > node->val)
			cur = cur->left;
		else
			;
	}

	if (prev == nullptr)
		root = node;
	else if (prev->val < node->val)
		prev->right = node;
	else if (prev->val > node->val)
		prev->left = node;
	else
		;
	return root;
}