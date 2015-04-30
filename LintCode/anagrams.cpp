#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
//题目描述：
//解法描述：将每个字符串排序，用map保存对应的字符串数组

std::vector<std::string> anagrams(std::vector<std::string> &strs)
{
	std::unordered_map<std::string, std::vector<std::string>> m;
	std::vector<std::string> result;

	for (int i = 0; i < strs.size(); ++i)
	{
		std::string s = strs[i];
		std::sort(s.begin(), s.end());
		m[s].push_back(strs[i]);
	}

	std::unordered_map<std::string, std::vector<std::string>>::iterator iter = m.begin();
	while (iter != m.end())
	{
		if (iter->second.size() > 1)
		{
			result.insert(result.end(), iter->second.begin(), iter->second.end());
		}
		++iter;
	}
	return result;
}