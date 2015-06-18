#include<vector>

//题目描述：给定一个数组，把该数组建成一个最小堆
//解法描述：和建立最大堆类似

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