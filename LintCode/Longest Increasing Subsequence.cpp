#include<vector>
#include<algorithm>
//题目描述：给定一个数组，找到其中的最长上升子序列的长度
//解法描述：动态规划，同样是局部最优和全局最优，dp[i]表示从0到i的序列中的最长上升子序列的长度，那么dp[i] = max(dp[j]) + 1,
//         并且nums[i] >= nums[j]
int longestIncreasingSubsequence(std::vector<int> nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> dp(nums.size(), 0);
	dp[0] = 1;
	int result = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		int max_length = 1;//注意这里，初始值为1
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] >= nums[j])
				max_length = std::max(max_length, dp[j] + 1);
		}
		dp[i] = max_length;
		result = std::max(result, dp[i]);
	}
	return result;
}