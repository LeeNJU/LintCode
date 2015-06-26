#include"Node.h"
//题目描述：给定两棵树T1和T2，T1有上百万个节点，T2有几百个节点，判断T2是不是T1的子树
//解法描述：递归，注意二叉树中可能包含相同的元素，当T1的元素和T2的元素相等的时候，要递归判断这两个子树是否相等，如果不等，要
//         继续递归判断是否是子树

bool isSame(TreeNode* T1, TreeNode* T2) //是否是相等的树
{
	if (T1 == nullptr && T2 == nullptr)
		return true;
	if (T1 != nullptr && T2 != nullptr && T1->val == T2->val)
		return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
	return false;
}
bool isSubtree(TreeNode *T1, TreeNode *T2) 
{
	if (T2 == nullptr)
		return true;
	if (T1 == nullptr)
		return false;

	bool result = false;
	if (T1->val == T2->val) //值相等要判断是否是相等的树
		result = isSame(T1, T2);

	if (!result) //不是相等的树，要继续判断
		result = isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
	return result;
}