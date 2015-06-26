#include<vector>

//题目描述：给定两个已序数组，把这两个数组合并，行程一个新的数组
//解法描述：看代码

std::vector<int> mergeSortedArray(std::vector<int>& A, std::vector<int>& B)
{
	std::vector<int> result(A.size() + B.size(), 0);
	int i = 0, j = 0, k = 0;
	while (i < A.size() && j < B.size())
	{
		if (A[i] <= B[j])
			result[k++] = A[i++];
		else
			result[k++] = B[j++];
	}
	if (i == A.size())
		std::copy(B.begin() + j, B.end(), result.begin() + k);
	else
		std::copy(A.begin() + i, A.end(), result.begin() + k);
	return result;
}