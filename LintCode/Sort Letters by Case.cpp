#include<string>
//��Ŀ����������һ���ַ���ֻ������Сд�ַ������ַ������в�����ʹ��Сд�ַ���ǰ�棬��д�ַ��ں���
//�ⷨ�������𲽰Ѵ�д�ַ����������

void sortLetters(std::string &letters)
{
	for (int i = 0, j = letters.size(); i < j;)
	{
		if (letters[i] < 'a')
			std::swap(letters[i], letters[--j]);
		else
			++i;
	}
}