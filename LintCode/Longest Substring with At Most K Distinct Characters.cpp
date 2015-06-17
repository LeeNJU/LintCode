#include<string>
#include<unordered_map>
#include<algorithm>
//��Ŀ����������һ���ַ������ҵ�����Ӵ�������Ӵ�������k����ͬ���ַ�
//�ⷨ������Two Pointer, i��jά��һ�����ڣ�hashtable�洢��ǰ���ڵ��ַ��ĳ��ִ�������hashtable�Ĵ�С����k��ʱ���ƶ�i

int lengthOfLongestSubstringKDistinct(std::string s, int k)
{
	int length = 0;
	std::unordered_map<char, int> m;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		++m[s[j]];
		while(m.size() > k) //hashtable����k���ƶ�i
		{
			--m[s[i]];
			if (m[s[i]] <= 0) //s[i]���ܳ��ֶ�Σ���С�ڵ���0��ʱ��ɾ��
				m.erase(s[i]);
			++i;
		}
		length = std::max(length, j - i + 1);
	}
	return length;
}