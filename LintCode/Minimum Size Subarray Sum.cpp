#include<vector>
#include<algorithm>
//��Ŀ����������һ�������һ��ֵs���ҵ������еĳ�����С�������飬�ǵ�������ĺʹ��ڵ���s
//�ⷨ������ά��һ������[i,j],�ǵ������ڵ�Ԫ�ش��ڵ���s��Ȼ������ƶ�i���вü�
int minimumSize(std::vector<int>& nums, int s) 
{
	int result = nums.size() + 1;
	int sum = 0, i = 0, j = 0;
	for (int k = 0; k < nums.size(); ++k)
	{
		if (nums[k] >= s)
			return 1;
		else if (sum + nums[k] < s)
		{
			sum += nums[k];
			j = k;
		}
		else
		{
			sum += nums[k];
			j = k;
			while (i <= j && (sum - nums[i]) >= s)
			{
				sum -= nums[i++];
			}
			result = std::min(result, j - i + 1);
		}
	}
	return result == nums.size() + 1 ? -1 : result;
}