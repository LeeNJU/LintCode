#include<string>
#include<unordered_map>

//题目描述：给定两个字符串，判断他们是不是anagram（字符相同但是位置顺序不同）
//解法描述：存储第一个字符串中每个字符的个数，扫描第二个字符串，一次减去1，最后判断

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