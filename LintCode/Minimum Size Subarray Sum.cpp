#include<vector>
#include<algorithm>
//题目描述：给定一个数组和一个值s，找到数组中的长度最小的子数组，是的子数组的和大于等于s
//解法描述：维护一个区间[i,j],是的区间内的元素大于等于s，然后向后移动i进行裁剪
int minimumSize(std::vector<int>& nums, int s) 
{
	int result = nums.size() + 1;
	int sum = 0, i = 0, j = 0;
	for (int k = 0; k < nums.size(); ++k)
	{
		if (nums[k] >= s)
			return 1;
		else if (sum + nums[k] < s)
		{
			sum += nums[k];
			j = k;
		}
		else
		{
			sum += nums[k];
			j = k;
			while (i <= j && (sum - nums[i]) >= s)
			{
				sum -= nums[i++];
			}
			result = std::min(result, j - i + 1);
		}
	}
	return result == nums.size() + 1 ? -1 : result;
}