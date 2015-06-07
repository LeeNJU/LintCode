#include<vector>
#include<unordered_map>

//题目描述：给定一个数组，找到其中的一个子数组，使得子数组的和为0，假设解总是存在
//解法描述；遍历数组，依次记录累加的和以及对应的下标，当出现两个和一样的时候，说明这两个和之间的子数组的和为0

std::vector<int> subarraySum(std::vector<int> nums)
{
	std::vector<int> result;
	std::unordered_map<int, int> m;

	int sum = 0;
	m[0] = -1;//加入虚拟节点0，-1，为了求出[-2,2,4]这样的解，当求出和为0的时候，前面必须得有和为0的元素
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		if (m.count(sum) != 0)
		{
			result.push_back(m[sum] + 1);
			result.push_back(i);
			return result;
		}
		else
			m[sum] = i;
	}
	return result;
}
