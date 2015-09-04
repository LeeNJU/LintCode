#include<vector>
//��Ŀ����������һ�����飬�ҵ����г��ִ�������n/3����
//�ⷨ���������ִ���n/3�����������������ͶƱ�㷨
std::vector<int> majorityElement(std::vector<int>& nums) 
{
	std::vector<int> result;
	if (nums.empty())
		return result;

	int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{

		if (candidate1 == nums[i])//ע������if������˳��
			++count1;
		else if (candidate2 == nums[i])
			++count2;
		else if (count1 == 0)
		{
			candidate1 = nums[i];
			++count1;
		}
		else if (count2 == 0)
		{
			candidate2 = nums[i];
			++count2;
		}
		else//����Ҫע��
		{
			--count1;
			--count2;
		}
	}

	count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == candidate1)
			++count1;
		else if (nums[i] == candidate2)//����Ҫд��else if���г̣���ֹcandidate1��candidate2��ȵ����
			++count2;
	}
	if (count1 > nums.size() / 3)
		result.push_back(candidate1);
	if (count2 > nums.size() / 3)
		result.push_back(candidate2);
	return result;
}