#include<string>
#include<unordered_map>
//��Ŀ�������ж��ַ���B�е��ַ�����A�г���

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