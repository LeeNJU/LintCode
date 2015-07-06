#include<vector>
#include<unordered_map>

//题目描述：给定一个数组和一个值k，找到数组中出现次数大于n/k的元素
//解法描述：用hashtable记录每个元素出现的次数

int majorityNumber(std::vector<int> nums, int k) 
{
	std::unordered_map<int, int> m;
	int count = nums.size() / k;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > count)
			return nums[i];
	}
}