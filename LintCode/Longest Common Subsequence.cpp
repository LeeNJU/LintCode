#include<vector>
#include<string>
#include<algorithm>
//题目描述：给定两个字符串，求出最长公共子序列的最大长度
//解法描述：二维动态规划，递推公式分两种情况，A[i]和B[j]相等和不等的情况

int longestCommonSubsequence(std::string A, std::string B) 
{
	std::vector<std::vector<int>> dp(A.size() + 1, std::vector<int>(B.size() + 1, 0));
	int result = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			if (A[i] == B[j])
				dp[i + 1][j + 1] = std::max(std::max(dp[i + 1][j], dp[i][j + 1]), dp[i][j] + 1);
			else
				dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
			result = std::max(result, dp[i + 1][j + 1]);
		}
	}
	return result;
}