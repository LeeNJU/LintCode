#include"Node.h"

//题目描述：给定一个二叉树的根节点和树中的两个节点，找到这两个节点最近的公共祖先节点
//解法描述：递归查找，从左右子树分别找两个节点

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (root == nullptr || root->val == A->val || root->val == B->val) //找到其中一个节点的父节点 
		return root;

	TreeNode* left = lowestCommonAncestor(root->left, A, B); //返回在左子树中查找的结果
	TreeNode* right = lowestCommonAncestor(root->right, A, B); //返回在右子树中查找的结果

	if (left != nullptr && right != nullptr) //都不为空，说明两个节点分别在root的左右子树
		return root;
	else if (left == nullptr) //左子树为空，说明在右子树
		return right;
	else if (right == nullptr) //右子树为空，说明在左子树
		return left;
	else
		;
}