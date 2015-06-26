#include<vector>

//题目描述：给定一个二维矩阵，每一行每一列都按从小到大排列，每一行每一列都没有重复元素，从中找出target出现的次数
//解法描述：从第一行的最后一个元素开始查找
int searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
{
	int count = 0;
	if (matrix.empty())
		return 0;

	int row = matrix.size(), col = matrix[0].size();
	int i = 0, j = col - 1;
	while (i < row && j >= 0)
	{
		if (matrix[i][j] == target) //找到目标元素，坐标往左下角移动
		{
			++count;
			--j;
			++i;
		}
		else if (matrix[i][j] < target) //元素比target小，只能在下一行查找
			++i;
		else //元素比target大，只能在同一行的前一列查找
			--j;
	}
	return count;
}