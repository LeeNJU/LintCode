#include"Node.h"
#include<vector>
#include<stack>

//题目描述：给定一个二叉树和两个值k1和k2，从二叉树中找到范围在k1和k2之间的数，这些数从小到大排列
//解法描述：中序遍历

std::vector<int> searchRange(TreeNode* root, int k1, int k2)
{
	std::vector<int> result;
	const TreeNode *p = root;
	std::stack<const TreeNode *> s;
	while (!s.empty() || p != nullptr)
	{
		if (p != nullptr) //把从根节点开始一直到最左边的节点上的所有节点压入栈中
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			if (p->val <= k2 && p->val >= k1)
				result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}