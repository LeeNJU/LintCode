//题目描述：返回斐波那契数列的第n个数
//解法描述：用prev和current两个变量依次相加

int fibonacci(int n) 
{
	if (n == 1)
		return 0;

	int prev = 0, current = 1;
	for (int i = 2; i < n; ++i) //从2开始
	{
		int temp = current;
		current += prev;
		prev = temp;
	}
	return current;
}