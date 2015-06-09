#include<algorithm>
#include<vector>
//题目描述：给定两个数组A和B，从中找到两个元素A[i]和B[j]，使得这两个元素的差的绝对值最小
//解法描述：先把两个数组排序，然后遍历两个数组，记录他们差的最小值

int smallestDifference(std::vector<int> &A, std::vector<int> &B)
{
	sort(A.begin(), A.end());//排序
	sort(B.begin(), B.end());
	int result = INT_MAX;
	for (int i = 0, j = 0; i < A.size() && j < B.size();)
	{
		result = std::min(result, abs(A[i] - B[j]));
		if (A[i] <= B[j])
			++i;
		else
			++j;
	}
	return result;
}