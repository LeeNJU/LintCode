#include<string>
#include<unordered_map>
#include<algorithm>
//题目描述：给定一个字符串，找到最长的子串，这个子串最多包含k个不同的字符
//解法描述：Two Pointer, i和j维护一个窗口，hashtable存储当前窗口的字符的出现次数，当hashtable的大小超过k的时候，移动i

int lengthOfLongestSubstringKDistinct(std::string s, int k)
{
	int length = 0;
	std::unordered_map<char, int> m;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		++m[s[j]];
		while(m.size() > k) //hashtable超过k，移动i
		{
			--m[s[i]];
			if (m[s[i]] <= 0) //s[i]可能出现多次，当小于等于0的时候，删除
				m.erase(s[i]);
			++i;
		}
		length = std::max(length, j - i + 1);
	}
	return length;
}