#include<algorithm>
//题目描述：给定两个整数，判断这两个整数的二进制表示中就多少位是不同的
//解法描述：从右边的位逐一比较，然后向右移位。要特别注意负数的情况，把负数换成整数再比

int bitSwapRequired(int a, int b)
{
	int result = 0;
	int count = 1;
	while (count <= 32)
	{
		if (abs(a) % 2 != abs(b) % 2)//负数换成正数
			++result;
		a = a >> 1;
		b = b >> 1;
		++count;
	}
	return result;
}