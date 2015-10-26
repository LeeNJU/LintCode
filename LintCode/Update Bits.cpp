//题目描述:给定整数n和m，把n的i到j位设为m
//解法描述:先把n的i到j位设为0,再与m相加

int updateBits(int n, int m, int i, int j)
{
	int mask = 0;
	if (j < 31)//计算掩码
		mask = ~((1 << (j + 1)) - (1 << i));
	else
		mask = (1 << i) - 1;
	return (m << i) + (mask & n);//mask & n把n的i到j位设为0，其余位不变
}