#include<vector>

//��Ŀ����������һ����СΪn�����飬����0��n�⼸�����֣�����ȱ��һ�����֣��ҵ��������
//�ⷨ������һ��ɨ�裬��Ԫ�طŵ����ʵ�λ�ã������0�ŵ�0λ�ã�1�ŵ�1λ��

int findMissing(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i)//���nums[i]���ں��ʵ�λ�ã��Ͱ�nums[i]�ŵ����ʵ�λ�ã����±�Ϊnums[i]��λ��
		{
			if (nums[i] == nums.size() || nums[i] == i)//ע�����������
				break;
			std::swap(nums[i], nums[nums[i]]);
		}
	}
	for (int i = 0; i < nums.size(); ++i)//�ҵ�һ����ƥ���Ԫ�ؾ��Ǵ�
	{
		if (nums[i] != i)
			return i;
	}
	return nums.size();
}