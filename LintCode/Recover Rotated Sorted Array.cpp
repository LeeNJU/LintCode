#include<vector>

//��Ŀ����������һ���������飬�����鱻��ת���ˣ�����Ҫ�ָ��������˳������[3,4,1,2],�ָ���[1,2,3,4]
//�ⷨ���������ҵ�����ת��λ�ã�Ȼ��ֱ�ת

void recoverRotatedSortedArray(std::vector<int>& nums)
{
	int index = 0;
	for (int i = 1; i < nums.size(); ++i) //�ҵ�����ת��λ��
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