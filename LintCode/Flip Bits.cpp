#include<algorithm>
//��Ŀ���������������������ж������������Ķ����Ʊ�ʾ�оͶ���λ�ǲ�ͬ��
//�ⷨ���������ұߵ�λ��һ�Ƚϣ�Ȼ��������λ��Ҫ�ر�ע�⸺����������Ѹ������������ٱ�

int bitSwapRequired(int a, int b)
{
	int result = 0;
	int count = 1;
	while (count <= 32)
	{
		if (abs(a) % 2 != abs(b) % 2)//������������
			++result;
		a = a >> 1;
		b = b >> 1;
		++count;
	}
	return result;
}