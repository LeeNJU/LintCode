#include<vector>
//题目描述：给定一个二维数组，要求以zig-zag的方式输出数组元素
//解法描述：用flag标记移动的方向，是从下往上还是从上往下， 注意边界条件

std::vector<int> printZMatrix(std::vector<std::vector<int>>& matrix) {
	std::vector<int> result;
	bool flag = true;  //表示移动的方向
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