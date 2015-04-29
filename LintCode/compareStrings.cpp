#include<string>
#include<unordered_map>
//题目描述：判断字符串B中的字符都在A中出现

bool compareStrings(std::string A, std::string B)
{
	std::unordered_map<char, int> m;
	for (int i = 0; i < A.size(); ++i)
		++m[A[i]];

	for (int i = 0; i < B.size(); ++i)
	{
		--m[B[i]];
		if (m[B[i]] < 0)
			return false;
	}
	return true;
}