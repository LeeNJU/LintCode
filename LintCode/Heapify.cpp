#include<vector>

//��Ŀ����������һ�����飬�Ѹ����齨��һ����С��
//�ⷨ�������ͽ�����������

void min_heapify(std::vector<int>& A, int index)
{
	int smallest = index;
	int left_child = 2 * index + 1;
	int right_child = 2 * index + 2;
	if (left_child < A.size() && A[left_child] < A[smallest])
		smallest = left_child;
	if (right_child < A.size() && A[right_child] < A[smallest])
		smallest = right_child;

	if (smallest != index)
	{
		std::swap(A[smallest], A[index]);
		min_heapify(A, smallest);
	}
}

void heapify(std::vector<int> &A)
{
	for (int i = (A.size() - 1) / 2; i >= 0; --i)
		min_heapify(A, i);
}