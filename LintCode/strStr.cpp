#include<string>
//题目描述：给定两个字符串A和B，判断B是否是A的子串
//解法描述：暴力求解

int strStr(const char *source, const char *target)
{
	if (source == nullptr || target == nullptr)//排除特殊条件
		return -1;

	int lengthA = strlen(source), lengthB = strlen(target);
	if (lengthB == 0)
		return 0;
	
	for (int i = 0; i <= (lengthA - lengthB); ++i)
	{
		if (source[i] == target[0])
		{
			int index = i;
			for (int j = 0; j < lengthB; ++j, ++index)
			{
				if (source[index] != target[j])
					break;
			}
			if (index - i == lengthB)
				return i;
		}
	}
	return -1;
}