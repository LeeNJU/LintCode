#include<vector>

//��Ŀ����������һ�����飬���ܰ����ظ�Ԫ�أ���һ��target���������в��Ҹ�Ԫ�ص�һ�γ��ֵ��±�
//�ⷨ���������ֲ���
int binarySearch(std::vector<int> &array, int target) 
{
	int left = 0, right = array.size() - 1, middle = 0;
	bool exist = false;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (array[middle] == target)
			exist = true;

		if (array[middle] < target)
			left = middle + 1;
		else
			right = middle;
	}
	return exist == true ? left : -1;
}