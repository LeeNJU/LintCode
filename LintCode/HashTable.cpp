#include<vector>
#include"Node.h"

//��Ŀ����������һ��hash���飬�����hash������ɢ��
//�ⷨ������������ɢ�еĲ���ȥ��
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
				if (index < 0) //�ڵ��ֵ����Ϊ��������˼���������±����Ϊ����
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