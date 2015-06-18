#include"Node.h"

//��Ŀ����������һ���������ĸ��ڵ�����е������ڵ㣬�ҵ��������ڵ�����Ĺ������Ƚڵ�
//�ⷨ�������ݹ���ң������������ֱ��������ڵ�

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (root == nullptr || root->val == A->val || root->val == B->val) //�ҵ�����һ���ڵ�ĸ��ڵ� 
		return root;

	TreeNode* left = lowestCommonAncestor(root->left, A, B); //�������������в��ҵĽ��
	TreeNode* right = lowestCommonAncestor(root->right, A, B); //�������������в��ҵĽ��

	if (left != nullptr && right != nullptr) //����Ϊ�գ�˵�������ڵ�ֱ���root����������
		return root;
	else if (left == nullptr) //������Ϊ�գ�˵����������
		return right;
	else if (right == nullptr) //������Ϊ�գ�˵����������
		return left;
	else
		;
}