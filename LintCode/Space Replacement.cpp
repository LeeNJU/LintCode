//��Ŀ����������һ���ַ��������ַ����еĿո���%20�滻�������ַ������㹻�ռ�����滻�������滻��ĳ���
//�ⷨ����:��������ַ����ĳ��ȣ�Ȼ��ӵ���������

int replaceBlank(char string [], int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i) // ͳ�ƿո������
	{
		if (string[i] == ' ')
			++count;
	}

	int result = length + count * 2;//���յĳ���
	int index = result - 1;
	for (int i = length - 1; i >= 0; --i)//���������и���
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