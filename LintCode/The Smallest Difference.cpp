#include<algorithm>
#include<vector>
//��Ŀ������������������A��B�������ҵ�����Ԫ��A[i]��B[j]��ʹ��������Ԫ�صĲ�ľ���ֵ��С
//�ⷨ�������Ȱ�������������Ȼ������������飬��¼���ǲ����Сֵ

int smallestDifference(std::vector<int> &A, std::vector<int> &B)
{
	sort(A.begin(), A.end());//����
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