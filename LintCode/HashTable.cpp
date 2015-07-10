#include<vector>
#include"Node.h"

//题目描述：给定一个hash数组，对这个hash数组再散列
//解法描述：按照再散列的操作去做
std::vector<ListNode*> rehashing(std::vector<ListNode*> hashTable) {
	int size = hashTable.size() * 2;
	std::vector<ListNode*> rehashTable(size);
	for (int i = 0; i < hashTable.size(); ++i)
	{
		if (hashTable[i] != nullptr)
		{
			ListNode* cur = hashTable[i];
			while (cur)
			{
				ListNode* next = cur->next;
				cur->next = nullptr;
				int index = cur->val % (size);
				if (index < 0) //节点的值可能为负数，因此计算出来的下标可能为负数
					index += size;
				ListNode* t = rehashTable[index];
				if (t == nullptr)
					rehashTable[index] = cur;
				else
				{
					while (t->next)
						t = t->next;
					t->next = cur;
				}
				cur = next;
			}
		}
	}
	return rehashTable;
}