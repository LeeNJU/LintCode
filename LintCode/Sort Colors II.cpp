#include<vector>
#include<algorithm>

//题目描述：给定一个数组有k种颜色，每种颜色用1到k表示，进行排序，不准用标准库
//解法描述：两层循环，先把1排到最前面，再把排2，再排3,...
void sortColors2(std::vector<int> &colors, int k)
{
	int index = -1;//index表示当前已经排好序的最后一个元素
	for (int i = -1; i < k - 1; ++i)//i控制当前要排那一个数字
	{
		int number = i + 2;
		for (int j = index + 1; j < colors.size(); ++j)
		{
			if (colors[j] == number)
				std::swap(colors[++index], colors[j]);
		}
	}
}