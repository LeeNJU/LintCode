//��Ŀ����:��������n��m����n��i��jλ��Ϊm
//�ⷨ����:�Ȱ�n��i��jλ��Ϊ0,����m���

int updateBits(int n, int m, int i, int j)
{
	int mask = 0;
	if (j < 31)//��������
		mask = ~((1 << (j + 1)) - (1 << i));
	else
		mask = (1 << i) - 1;
	return (m << i) + (mask & n);//mask & n��n��i��jλ��Ϊ0������λ����
}