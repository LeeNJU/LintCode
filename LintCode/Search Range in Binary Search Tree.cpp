#include"Node.h"
#include<vector>
#include<stack>

//��Ŀ����������һ��������������ֵk1��k2���Ӷ��������ҵ���Χ��k1��k2֮���������Щ����С��������
//�ⷨ�������������

std::vector<int> searchRange(TreeNode* root, int k1, int k2)
{
	std::vector<int> result;
	const TreeNode *p = root;
	std::stack<const TreeNode *> s;
	while (!s.empty() || p != nullptr)
	{
		if (p != nullptr) //�ѴӸ��ڵ㿪ʼһֱ������ߵĽڵ��ϵ����нڵ�ѹ��ջ��
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