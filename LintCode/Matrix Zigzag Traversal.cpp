#include<vector>
//��Ŀ����������һ����ά���飬Ҫ����zig-zag�ķ�ʽ�������Ԫ��
//�ⷨ��������flag����ƶ��ķ����Ǵ������ϻ��Ǵ������£� ע��߽�����

std::vector<int> printZMatrix(std::vector<std::vector<int>>& matrix) {
	std::vector<int> result;
	bool flag = true;  //��ʾ�ƶ��ķ���
	for (int i = 0, j = 0; i < matrix.size() && j < matrix[0].size();)
	{
		result.push_back(matrix[i][j]);
		if (flag)
		{
			if (i - 1 >= 0 && j + 1 < matrix[0].size())
			{
				--i;
				++j;
			}
			else
			{
				flag = false;
				if (j + 1 < matrix[0].size())
					++j;
				else
					++i;
			}
		}
		else
		{
			if (j - 1 >= 0 && i + 1 < matrix.size())
			{
				--j;
				++i;
			}
			else
			{
				flag = true;
				if (i + 1 < matrix.size())
					++i;
				else
					++j;
			}
		}
	}
	return result;
}