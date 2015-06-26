#include<vector>

//题目描述：给定一个未排序的数组，求中位数
//解法描述：利用快排的partition操作

int partition(std::vector<int>& nums, int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j < right; ++j)
	{
		if (nums[j] < pivot)
			std::swap(nums[j], nums[++i]);
	}
	std::swap(nums[right], nums[++i]);
	return i;
}

int median(std::vector<int>& nums)
{
	int position = 0;
	if (nums.size() % 2 == 0) //找到最终要求的中位数的下标
		position = nums.size() / 2 - 1;
	else
		position = nums.size() / 2;

	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int index = partition(nums, left, right);
		if (index == position)
			return nums[index];
		else if (index < position)
			left = index + 1;
		else
			right = index - 1;
	}
	return -1;
}