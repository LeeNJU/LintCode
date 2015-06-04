#include<vector>

//题目描述：给定一个数组，划分数组使得奇数在前面，偶数在后面
//解法描述：划分操作类似于快排的划分操作，不断交换即可

void partitionArray(std::vector<int> &nums)
{
	int first = 0, last = nums.size();//first指向最后一个奇数的下一个位置，last指向偶数位置
	while (first < last)
	{
		if (nums[first] % 2 == 0)
		{
			--last;
			int t = nums[last];
			nums[last] = nums[first];
			nums[first] = t;
		}
		else
			++first;
	}
}