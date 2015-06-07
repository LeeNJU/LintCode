#include<vector>
#include<algorithm>

//��Ŀ����������һ�������һ��ֵk������������飬ʹ�����б�kС��Ԫ�����������ߣ���k���ڻ���ڵ�Ԫ���������ұߣ����ص�һ�����ڵ���k��Ԫ���±�
//�ⷨ�����������ڿ��ŵĻ��֣�indexָ�����һ�����ڵ���k��Ԫ���±꣬���ν���

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