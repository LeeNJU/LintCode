#include<vector>
#include<unordered_map>

//��Ŀ����������һ�������һ��ֵk���ҵ������г��ִ�������n/k��Ԫ��
//�ⷨ��������hashtable��¼ÿ��Ԫ�س��ֵĴ���

int majorityNumber(std::vector<int> nums, int k) 
{
	std::unordered_map<int, int> m;
	int count = nums.size() / k;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > count)
			return nums[i];
	}
}