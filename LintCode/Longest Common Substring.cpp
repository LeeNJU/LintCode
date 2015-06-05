#include<vector>
#include<string>

//题目描述：给定两个字符串，求出这两个字符串最长公共子串的长度
//解法描述：二维动态规划，如果A[i] == B[j],那么dp[i][j] = dp[i - 1][j - 1] + 1,否则dp[i][j] = 0;用一个变量保存遍历过程中出现的最大长度，
//注意dp[i][j]表示A[0-i]和B[0-j]的最长公共子串的长度，但是并不完全正确，由于有dp[i][j] = 0的操作，前面字符串的长度并没有传递到后面，因此dp[A-1][B-1]
//并不表示A和B的最长公共子串的长度，所以需要一个变量来记录最大长度

int longestCommonSubstring(std::string &A, std::string &B) {
	std::vector<std::vector<int>> t(A.size() + 1, std::vector<int>(B.size() + 1, 0));
	int max_length = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			if (A[i] == B[j])
				t[i + 1][j + 1] = t[i][j] + 1;
			else
				t[i + 1][j + 1] = 0;
			if (t[i + 1][j + 1] > max_length)
				max_length = t[i + 1][j + 1];
		}
	}
	return max_length;
}