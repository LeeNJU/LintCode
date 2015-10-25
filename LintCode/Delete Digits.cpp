#include<string>
#include<vector>
//题目描述:给定一个字符串，只包含数字0-9,从中删除k个字符，使得剩下的字符串所代表的数字最小
//解法描述:删除一个字符相当于用后面的字符代替删除的字符，所以删除那些比后面字符串要大的字符
std::string DeleteDigits(std::string A, int k) 
{
	int length = A.size() - k;
	for (int i = 0; i < k; ++i)//如果一个字符比后面相邻的字符串要大，那么删除该字符，注意循环结束后，被删除字符的个数
	{                          //可能小于k，但是所有的字符都是递增的
		for (int j = 0; j < A.size() - 1; ++j)
		{
			if (A[j] > A[j + 1])
			{
				A = A.substr(0, j) + A.substr(j + 1);
				break;
			}
		}
	}

	int index = 0;
	while (index < A.size() && A[index] == '0')//要忽略前面的0
		++index;

	return A.substr(index, length - index);//截取前面length个字符，但是要忽略前面的0
}