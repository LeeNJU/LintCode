#include"Node.h"

//题目描述：完成二叉树的插入操作
//解法描述：prev指向父节点，cur指向当前节点，逐层下降

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