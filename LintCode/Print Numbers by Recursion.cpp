#include<vector>

//题目描述：给定一个值n，得到从1到n位数，例如n=1，得到1到9， n=2，得到1到99，n=3，得到1到999
//解法描述：递归，每一层得到某一位的所有数字，第一层得到1位的所有数字，第二层得到2位的所有数字，第三层得到3位的所有数字。

void recursion(std::vector<int>& result, int start, int end, int depth)
{
	if (depth == 0)
		return;

	for (int i = start; i <= end; ++i)
		result.push_back(i);
	recursion(result, end + 1, end * 10 + 9, depth - 1);
}

std::vector<int> numbersByRecursion(int n) 
{
	std::vector<int> result;
	recursion(result, 1, 9, n);
	return result;
}