//题目描述：给定一个值n和k，0<=k<=9,从0到n的数字中找到数字k出现的次数，例如 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，k = 1，结果为5

int digitCounts(int k, int n)
{
	if (n <= 9)
		return n >= k ? 1 : 0;

	int count = 0;
	for (int i = 10; i <= n; ++i)
	{
		int value = i;
		while (value)
		{
			if (value % 10 == k)
				++count;
			value /= 10;
		}
	}
	return count + 1; //加上个位的1
}