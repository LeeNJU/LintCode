#include<vector>
#include<algorithm>
#include<unordered_map>
#include"Node.h"
//题目描述：给定一个有向图，找到其中弱连通子图的个数
//解法描述：union-find操作。用root的方式实现union-find
int root(std::unordered_map<int, int>& u, int label)//找到根节点
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
			if (rootA != rootB)//找到每个节点的根节点，有几个树就有几个弱连通子图
			{
				if (rootA <= rootB)
					u[rootA] = rootB;
				else
					u[rootB] = rootA;
			}
		}
	}

	std::unordered_map<int, std::vector<int>> t; //以根节点作为下标，把所有根相同的点放到vector中
	for (int i = 0; i < nodes.size(); ++i)
	{
		int r = root(u, nodes[i]->label);
		t[r].push_back(nodes[i]->label);
	}

	std::vector<std::vector<int>> result;
	std::unordered_map<int, std::vector<int>>::iterator iter = t.begin();
	while (iter != t.end())//排序
	{
		sort(iter->second.begin(), iter->second.end());
		result.push_back(iter->second);
		++iter;
	}
	return result;
}