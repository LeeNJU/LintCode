#include<vector>

//题目描述：给定一个数组，可能包含重复元素，和一个target，从数组中查找该元素第一次出现的下标
//解法描述：二分查找
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