#include<string>
#include<unordered_map>

//��Ŀ���������������ַ������ж������ǲ���anagram���ַ���ͬ����λ��˳��ͬ��
//�ⷨ�������洢��һ���ַ�����ÿ���ַ��ĸ�����ɨ��ڶ����ַ�����һ�μ�ȥ1������ж�

bool anagram(std::string s, std::string t)
{
	std::unordered_map<char, int> m;
	for (int i = 0; i < s.length(); ++i)
		++m[s[i]];

	for (int i = 0; i < t.length(); ++i)
	{
		--m[s[i]];
		if (m[s[i]] == 0)
			m.erase(s[i]);
	}

	return m.empty();
}