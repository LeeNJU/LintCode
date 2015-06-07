#include<vector>
#include<unordered_map>

//��Ŀ����������һ�����飬�ҵ����е�һ�������飬ʹ��������ĺ�Ϊ0����������Ǵ���
//�ⷨ�������������飬���μ�¼�ۼӵĺ��Լ���Ӧ���±꣬������������һ����ʱ��˵����������֮���������ĺ�Ϊ0

std::vector<int> subarraySum(std::vector<int> nums)
{
	std::vector<int> result;
	std::unordered_map<int, int> m;

	int sum = 0;
	m[0] = -1;//��������ڵ�0��-1��Ϊ�����[-2,2,4]�����Ľ⣬�������Ϊ0��ʱ��ǰ�������к�Ϊ0��Ԫ��
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
