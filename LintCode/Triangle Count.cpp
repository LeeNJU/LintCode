#include<vector>
#include<algorithm>
//��Ŀ����������һ�����������飬�ҳ�������������Ϊ�����εıߣ��ҳ����е����
//�ⷨ������������ָ�룬��������iָ�����һ��Ԫ�أ�jָ���һ��Ԫ�أ�kָ��iǰһ��Ԫ��


int triangleCount(std::vector<int> &S)
{
	if (S.size() <= 2)
		return 0;

	sort(S.begin(), S.end());  //������
	int result = 0;
	for (int i = S.size() - 1; i - 2 >= 0; --i)
	{
		for (int j = 0, k = i - 1; j < k;)
		{
			if (S[j] + S[k] <= S[i])
				++j;
			else
			{
				result += k - j; //�����ǹؼ�
				--k;
			}
		}
	}
	return result;
}