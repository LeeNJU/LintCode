#include<vector>

//题目描述：给定一个大小为n的数组，包含0到n这几个数字，其中缺少一个数字，找到这个数字
//解法描述：一遍扫描，把元素放到合适的位置，例如把0放到0位置，1放到1位置

int findMissing(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i)//如果nums[i]不在合适的位置，就把nums[i]放到合适的位置，即下标为nums[i]的位置
		{
			if (nums[i] == nums.size() || nums[i] == i)//注意这里的条件
				break;
			std::swap(nums[i], nums[nums[i]]);
		}
	}
	for (int i = 0; i < nums.size(); ++i)//找到一个不匹配的元素就是答案
	{
		if (nums[i] != i)
			return i;
	}
	return nums.size();
}