//��Ŀ����������쳲��������еĵ�n����
//�ⷨ��������prev��current���������������

int fibonacci(int n) 
{
	if (n == 1)
		return 0;

	int prev = 0, current = 1;
	for (int i = 2; i < n; ++i) //��2��ʼ
	{
		int temp = current;
		current += prev;
		prev = temp;
	}
	return current;
}