#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬�ҵ����е�����������еĳ���
//�ⷨ��������̬�滮��ͬ���Ǿֲ����ź�ȫ�����ţ�dp[i]��ʾ��0��i�������е�����������еĳ��ȣ���ôdp[i] = max(dp[j]) + 1,
//         ����nums[i] >= nums[j]
int longestIncreasingSubsequence(std::vector<int> nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> dp(nums.size(), 0);
	dp[0] = 1;
	int result = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		int max_length = 1;//ע�������ʼֵΪ1
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