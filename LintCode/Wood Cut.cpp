#include<vector>
#include<algorithm>
//题目描述：给定一个数组表示树木的长度和一个值k，对树木进行分割，使得获得相同长度的树木的个数要大于等于k，求能够进行
//         分割的最大长度，例如{34,13,23},k = 2,最大长度为17
//解法描述：每一个树木并不一定要进行分割，求出数组的最大元素，在[1,max]之间进行二分查找，每找到一个值，求出能够进行的
//         分割数，与k进行比较，大于等于k，向后查找，小于k，向左查找

int woodCut(std::vector<int> L, int k) 
{
	if (L.empty())
		return 0;

	int max = *max_element(L.begin(), L.end());//求出最大元素
	int first = 1, last = max, middle = 0;
	int length = 0;
	while (first <= last)//在[1, max]之间进行二分查找
	{
		middle = first + (last - first) / 2; //注意这里的计算方式
		int count = 0;
		for (int i = 0; i < L.size(); ++i) //当前长度为middle，求出切割数
			count += L[i] / middle;
		if (count >= k) //切割数大于k
		{
			length = middle > length ? middle : length;
			first = middle + 1;
		}
		else
			last = middle - 1;
	}
	return length;
}