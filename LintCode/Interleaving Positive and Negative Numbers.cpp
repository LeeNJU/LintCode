#include<vector>
//��Ŀ����������һ�����飬ֻ���������͸�����Ҫ����������������������ʽ������[-1, -2, -3, 4, 5, 6]���
//         [-1, 5, -2, 4, -3, 6],�Ⲣ��Ψһ
//�ⷨ�������Ȱ���������ɸ�����ǰ�����ں����ʽ��Ȼ���ٽ���������������λ��
void rerange(std::vector<int>& A) 
{
	if (A.empty())
		return;

	int positive = A.size(); //positive������¼������ʼ���±�
	for (int i = 0; i < A.size() && i < positive;)
	{
		if (A[i] > 0)
			std::swap(A[i], A[--positive]);
		else
			++i;
	}

	if (positive * 2 >= A.size()) //�������ĸ������������ĸ�������ô��ĵ�һ��Ԫ��ֻ���Ǹ���
	{
		for (int i = 1; i < A.size() - 1; i = i + 2)
			std::swap(A[i], A[positive++]);
	}
	else //�����������٣���ô��ĵ�һ��Ԫ��ֻ��������
	{
		for (int i = 0; i < A.size(); i = i + 2)
		{
			std::swap(A[i], A[positive++]);
		}
	}
}