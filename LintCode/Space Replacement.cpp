//题目描述：给定一个字符串，把字符串中的空格用%20替换，假设字符串有足够空间进行替换，返回替换后的长度
//解法描述:先算出新字符串的长度，然后从倒过来复制

int replaceBlank(char string [], int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i) // 统计空格的数量
	{
		if (string[i] == ' ')
			++count;
	}

	int result = length + count * 2;//最终的长度
	int index = result - 1;
	for (int i = length - 1; i >= 0; --i)//倒过来进行复制
	{
		if (string[i] == ' ')
		{
			string[index--] = '0';
			string[index--] = '2';
			string[index--] = '%';
		}
		else
			string[index--] = string[i];
	}
	return result;
}