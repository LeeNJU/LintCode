#include<vector>

//��Ŀ����������һ��ֵn���õ���1��nλ��������n=1���õ�1��9�� n=2���õ�1��99��n=3���õ�1��999
//�ⷨ�������ݹ飬ÿһ��õ�ĳһλ���������֣���һ��õ�1λ���������֣��ڶ���õ�2λ���������֣�������õ�3λ���������֡�

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