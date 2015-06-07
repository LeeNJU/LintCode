#include<vector>
#include<algorithm>

//题目描述：给定一个数组和一个值k，划分这个数组，使得所有比k小的元素在数组的左边，比k大于或等于的元素在数组右边，返回第一个大于等于k的元素下标
//解法描述：类似于快排的划分，index指向最后一个大于等于k的元素下标，依次交换

int partitionArray(std::vector<int> &nums, int k)
{
	int i = 0, index = nums.size();
	while (i < index)
	{
		if (nums[i] >= k)
			std::swap(nums[i], nums[--index]);
		else
			++i;
	}
	return index;
}