#include<vector>

//题目描述：给定一个已序数组，该数组被旋转过了，现在要恢复该数组的顺序，例如[3,4,1,2],恢复成[1,2,3,4]
//解法描述：先找到被旋转的位置，然后分别反转

void recoverRotatedSortedArray(std::vector<int>& nums)
{
	int index = 0;
	for (int i = 1; i < nums.size(); ++i) //找到被旋转的位置
	{
		if (nums[i] < nums[i - 1])
		{
			index = i;
			break;
		}
	}

	std::reverse(nums.begin(), nums.begin() + index);
	std::reverse(nums.begin() + index, nums.end());
	std::reverse(nums.begin(), nums.end());
}