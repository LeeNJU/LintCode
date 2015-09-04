#include<vector>
//题目描述：给定一个数组，找到其中出现次数大于n/3的数
//解法描述：出现大于n/3的数最多有两个，用投票算法
std::vector<int> majorityElement(std::vector<int>& nums) 
{
	std::vector<int> result;
	if (nums.empty())
		return result;

	int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{

		if (candidate1 == nums[i])//注意这里if条件的顺序
			++count1;
		else if (candidate2 == nums[i])
			++count2;
		else if (count1 == 0)
		{
			candidate1 = nums[i];
			++count1;
		}
		else if (count2 == 0)
		{
			candidate2 = nums[i];
			++count2;
		}
		else//这里要注意
		{
			--count1;
			--count2;
		}
	}

	count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == candidate1)
			++count1;
		else if (nums[i] == candidate2)//这里要写成else if的行程，防止candidate1和candidate2相等的情况
			++count2;
	}
	if (count1 > nums.size() / 3)
		result.push_back(candidate1);
	if (count2 > nums.size() / 3)
		result.push_back(candidate2);
	return result;
}