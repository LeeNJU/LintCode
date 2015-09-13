#include<vector>
#include<algorithm>
//��Ŀ����������һ�������ʾ��ľ�ĳ��Ⱥ�һ��ֵk������ľ���зָʹ�û����ͬ���ȵ���ľ�ĸ���Ҫ���ڵ���k�����ܹ�����
//         �ָ����󳤶ȣ�����{34,13,23},k = 2,��󳤶�Ϊ17
//�ⷨ������ÿһ����ľ����һ��Ҫ���зָ�����������Ԫ�أ���[1,max]֮����ж��ֲ��ң�ÿ�ҵ�һ��ֵ������ܹ����е�
//         �ָ�������k���бȽϣ����ڵ���k�������ң�С��k���������

int woodCut(std::vector<int> L, int k) 
{
	if (L.empty())
		return 0;

	int max = *max_element(L.begin(), L.end());//������Ԫ��
	int first = 1, last = max, middle = 0;
	int length = 0;
	while (first <= last)//��[1, max]֮����ж��ֲ���
	{
		middle = first + (last - first) / 2; //ע������ļ��㷽ʽ
		int count = 0;
		for (int i = 0; i < L.size(); ++i) //��ǰ����Ϊmiddle������и���
			count += L[i] / middle;
		if (count >= k) //�и�������k
		{
			length = middle > length ? middle : length;
			first = middle + 1;
		}
		else
			last = middle - 1;
	}
	return length;
}