#include<vector>
#include<algorithm>
#include<unordered_map>
#include"Node.h"
//��Ŀ����������һ������ͼ���ҵ���������ͨ��ͼ�ĸ���
//�ⷨ������union-find��������root�ķ�ʽʵ��union-find
int root(std::unordered_map<int, int>& u, int label)//�ҵ����ڵ�
{
	if (u.find(label) == u.end())
	{
		u[label] = label;
		return label;
	}

	while (u[label] != label)
		label = u[label];
	return label;
}

std::vector<std::vector<int>> connectedSet2(std::vector<DirectedGraphNode*>& nodes) 
{
	std::unordered_map<int, int> u;
	for (int i = 0; i < nodes.size(); ++i)
	{
		for (int j = 0; j < nodes[i]->neighbors.size(); ++j)
		{
			int rootA = root(u, nodes[i]->label);
			int rootB = root(u, nodes[i]->neighbors[j]->label);
			if (rootA != rootB)//�ҵ�ÿ���ڵ�ĸ��ڵ㣬�м��������м�������ͨ��ͼ
			{
				if (rootA <= rootB)
					u[rootA] = rootB;
				else
					u[rootB] = rootA;
			}
		}
	}

	std::unordered_map<int, std::vector<int>> t; //�Ը��ڵ���Ϊ�±꣬�����и���ͬ�ĵ�ŵ�vector��
	for (int i = 0; i < nodes.size(); ++i)
	{
		int r = root(u, nodes[i]->label);
		t[r].push_back(nodes[i]->label);
	}

	std::vector<std::vector<int>> result;
	std::unordered_map<int, std::vector<int>>::iterator iter = t.begin();
	while (iter != t.end())//����
	{
		sort(iter->second.begin(), iter->second.end());
		result.push_back(iter->second);
		++iter;
	}
	return result;
}