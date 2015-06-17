#include<vector>
#include<algorithm>
//题目描述：给定一个正整数数组，找出其中三个数作为三角形的边，找出所有的组合
//解法描述：用两个指针，从右往左，i指向最后一个元素，j指向第一个元素，k指向i前一个元素


int triangleCount(std::vector<int> &S)
{
	if (S.size() <= 2)
		return 0;

	sort(S.begin(), S.end());  //先排序
	int result = 0;
	for (int i = S.size() - 1; i - 2 >= 0; --i)
	{
		for (int j = 0, k = i - 1; j < k;)
		{
			if (S[j] + S[k] <= S[i])
				++j;
			else
			{
				result += k - j; //这里是关键
				--k;
			}
		}
	}
	return result;
}