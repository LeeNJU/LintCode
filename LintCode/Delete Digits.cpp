#include<string>
#include<vector>
//��Ŀ����:����һ���ַ�����ֻ��������0-9,����ɾ��k���ַ���ʹ��ʣ�µ��ַ����������������С
//�ⷨ����:ɾ��һ���ַ��൱���ú�����ַ�����ɾ�����ַ�������ɾ����Щ�Ⱥ����ַ���Ҫ����ַ�
std::string DeleteDigits(std::string A, int k) 
{
	int length = A.size() - k;
	for (int i = 0; i < k; ++i)//���һ���ַ��Ⱥ������ڵ��ַ���Ҫ����ôɾ�����ַ���ע��ѭ�������󣬱�ɾ���ַ��ĸ���
	{                          //����С��k���������е��ַ����ǵ�����
		for (int j = 0; j < A.size() - 1; ++j)
		{
			if (A[j] > A[j + 1])
			{
				A = A.substr(0, j) + A.substr(j + 1);
				break;
			}
		}
	}

	int index = 0;
	while (index < A.size() && A[index] == '0')//Ҫ����ǰ���0
		++index;

	return A.substr(index, length - index);//��ȡǰ��length���ַ�������Ҫ����ǰ���0
}