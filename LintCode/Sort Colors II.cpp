#include<vector>
#include<algorithm>

//��Ŀ����������һ��������k����ɫ��ÿ����ɫ��1��k��ʾ���������򣬲�׼�ñ�׼��
//�ⷨ����������ѭ�����Ȱ�1�ŵ���ǰ�棬�ٰ���2������3,...
void sortColors2(std::vector<int> &colors, int k)
{
	int index = -1;//index��ʾ��ǰ�Ѿ��ź�������һ��Ԫ��
	for (int i = -1; i < k - 1; ++i)//i���Ƶ�ǰҪ����һ������
	{
		int number = i + 2;
		for (int j = index + 1; j < colors.size(); ++j)
		{
			if (colors[j] == number)
				std::swap(colors[++index], colors[j]);
		}
	}
}