#include<vector>

//��Ŀ����������һ����ά����ÿһ��ÿһ�ж�����С�������У�ÿһ��ÿһ�ж�û���ظ�Ԫ�أ������ҳ�target���ֵĴ���
//�ⷨ�������ӵ�һ�е����һ��Ԫ�ؿ�ʼ����
int searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
{
	int count = 0;
	if (matrix.empty())
		return 0;

	int row = matrix.size(), col = matrix[0].size();
	int i = 0, j = col - 1;
	while (i < row && j >= 0)
	{
		if (matrix[i][j] == target) //�ҵ�Ŀ��Ԫ�أ����������½��ƶ�
		{
			++count;
			--j;
			++i;
		}
		else if (matrix[i][j] < target) //Ԫ�ر�targetС��ֻ������һ�в���
			++i;
		else //Ԫ�ر�target��ֻ����ͬһ�е�ǰһ�в���
			--j;
	}
	return count;
}