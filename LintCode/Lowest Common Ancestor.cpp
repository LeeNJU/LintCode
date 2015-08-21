#include"Node.h"

//题目描述：给定一个二叉树的根节点和树中的两个节点，找到这两个节点最近的公共祖先节点
//解法描述：自底向上递归

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (!root || root == A || root == B) 
		return root;
	TreeNode* left = lowestCommonAncestor(root->left, A, B); //判断A或者B是否在左子树中
	TreeNode* right = lowestCommonAncestor(root->right, A, B);
	if (left && right) //A和B在根节点两边
		return root;
	return left ? left : right;  // A和B都在左子树或者右子树
}