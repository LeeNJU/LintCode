#include<vector>
#include<algorithm>
//题目描述：给定一个数组，找到最长的递增序列的长度，这里的递增序列可以是从左往右递增，也可以是从右往左递增
//解法描述：动态规划，两边扫描。prev和cur用来计算当前一个递增子序列的长度，right_result用来保存最长的长度

int longestIncreasingContinuousSubsequence(std::vector<int>& A) {
	if (A.empty()) //判断为空的情况
		return 0;

	int prev = 1, cur = 1, right_result = 1;
	for (int i = 1; i < A.size(); ++i)//先计算从左往右的结果
	{
		if (A[i] >= A[i - 1]) //当前元素比前一个元素大，那么cur应该加1，prev的值更新为cur加1前的值
		{
			cur = prev + 1;
			prev = cur;
		}
		else //当前元素比前一个元素小，说明递增序列中断了，cur和prev都设为1
		{
			cur = 1;
			prev = 1;
		}
		right_result = std::max(right_result, cur);//right_result保存结果
	}

	prev = cur = 1;
	int left_result = 1;
	for (int i = A.size() - 2; i >= 0; --i)
	{
		if (A[i] >= A[i + 1])
		{
			cur = prev + 1;
			prev = cur;
		}
		else
		{
			cur = prev = 1;
		}
		left_result = std::max(left_result, cur);
	}
	return std::max(left_result, right_result);
}