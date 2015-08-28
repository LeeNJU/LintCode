#include<vector>
//题目描述：给定一个数组，只包含正数和负数，要求把数组编程正负数交错的形式，例如[-1, -2, -3, 4, 5, 6]变成
//         [-1, 5, -2, 4, -3, 6],解并不唯一
//解法描述：先把数组整理成负数在前正数在后的形式，然后再交换负数和正数的位置
void rerange(std::vector<int>& A) 
{
	if (A.empty())
		return;

	int positive = A.size(); //positive用来记录正数开始的下标
	for (int i = 0; i < A.size() && i < positive;)
	{
		if (A[i] > 0)
			std::swap(A[i], A[--positive]);
		else
			++i;
	}

	if (positive * 2 >= A.size()) //如果如果的个数多数正数的个数，那么解的第一个元素只能是负数
	{
		for (int i = 1; i < A.size() - 1; i = i + 2)
			std::swap(A[i], A[positive++]);
	}
	else //负数比正数少，那么解的第一个元素只能是正数
	{
		for (int i = 0; i < A.size(); i = i + 2)
		{
			std::swap(A[i], A[positive++]);
		}
	}
}