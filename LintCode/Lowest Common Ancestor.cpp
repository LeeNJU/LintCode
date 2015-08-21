#include"Node.h"

//��Ŀ����������һ���������ĸ��ڵ�����е������ڵ㣬�ҵ��������ڵ�����Ĺ������Ƚڵ�
//�ⷨ�������Ե����ϵݹ�

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (!root || root == A || root == B) 
		return root;
	TreeNode* left = lowestCommonAncestor(root->left, A, B); //�ж�A����B�Ƿ�����������
	TreeNode* right = lowestCommonAncestor(root->right, A, B);
	if (left && right) //A��B�ڸ��ڵ�����
		return root;
	return left ? left : right;  // A��B��������������������
}