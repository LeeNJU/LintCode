#include"Node.h"
#include<vector>
#include<string>
#include<algorithm>
class Solution 
{
private:
	std::string inorder;
	std::string preorder;
	int getValue(const std::string& s, int index)
	{
		int sign = 1;
		if (s[0] == '-')
		{
			++index;
			sign = -1;
		}

		int value = 0;
		for (int i = index; i < s.length() && s[i] != ','; ++i)
		{
			value = value * 10 + s[i] - '0';
		}
		return value * sign;
	}
	void serializeToString(TreeNode* root)
	{
		if (root == nullptr)
			return;

		preorder += std::to_string(root->val) + ",";
		serialize(root->left);
		inorder += std::to_string(root->val) + ",";
		serialize(root->right);
	}
	TreeNode* construct(std::string& pre, int preIndex, std::string& in, int index)
	{

	}
public:
	std::string serialize(TreeNode *root) 
	{
		return preorder;
	}

	TreeNode *deserialize(std::string data) 
	{

	}
};