#include<vector>

//��Ŀ����������һ�����飬��������ʹ��������ǰ�棬ż���ں���
//�ⷨ���������ֲ��������ڿ��ŵĻ��ֲ��������Ͻ�������

void partitionArray(std::vector<int> &nums)
{
	int first = 0, last = nums.size();//firstָ�����һ����������һ��λ�ã�lastָ��ż��λ��
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