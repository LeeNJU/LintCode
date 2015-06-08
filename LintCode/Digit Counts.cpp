//��Ŀ����������һ��ֵn��k��0<=k<=9,��0��n���������ҵ�����k���ֵĴ��������� [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]��k = 1�����Ϊ5

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
	return count + 1; //���ϸ�λ��1
}