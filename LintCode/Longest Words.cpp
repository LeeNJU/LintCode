#include<vector>
#include<string>

//��Ŀ����������һ���ַ������飬�ҵ����г�������ַ��������أ�����ַ��������ж��
//�ⷨ������һ��ɨ�裬��max���浱ǰ����󳤶ȣ����ϸ���max��ֵ

std::vector<std::string> longestWords(std::vector<std::string> &dictionary)
{
	std::vector<std::string> result;
	int max = 0;
	for (int i = 0; i < dictionary.size(); ++i)
	{
		if (dictionary[i].size() > max)//��ǰԪ�س�����󣬰�֮ǰ�����Ԫ��ȥ�����ѵ�ǰԪ�ؼ��뵽result��
		{
			result.clear();
			max = dictionary[i].size();
			result.push_back(dictionary[i]);
		}
		else if (dictionary[i].size() == max)//������ȣ����뵽result��
			result.push_back(dictionary[i]);
	}
	return result;
}