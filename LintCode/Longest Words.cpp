#include<vector>
#include<string>

//题目描述：给定一个字符串数组，找到其中长度最长的字符串并返回，最长的字符串可能有多个
//解法描述：一遍扫描，用max保存当前的最大长度，不断更新max的值

std::vector<std::string> longestWords(std::vector<std::string> &dictionary)
{
	std::vector<std::string> result;
	int max = 0;
	for (int i = 0; i < dictionary.size(); ++i)
	{
		if (dictionary[i].size() > max)//当前元素长度最大，把之前保存的元素去掉，把当前元素加入到result中
		{
			result.clear();
			max = dictionary[i].size();
			result.push_back(dictionary[i]);
		}
		else if (dictionary[i].size() == max)//长度相等，加入到result中
			result.push_back(dictionary[i]);
	}
	return result;
}