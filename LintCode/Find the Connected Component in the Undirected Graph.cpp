#include<vector>
#include<unordered_map>
#include<queue>
#include"Node.h"

//题目描述：给定一个无向图，找到其中连通子图的个数
//解法描述：遍历每一个节点，如果该节点没有被访问过，那么进行广搜，找到一个连通子图，并把子图中的点进行标记。
void bfs(UndirectedGraphNode* node, std::unordered_map<UndirectedGraphNode*, bool>& visit, std::vector<int>& t)
{
	if (node == nullptr)
		return;

	std::queue<UndirectedGraphNode*> q;
	q.push(node);
	visit[node] = true;
	t.push_back(node->label);
	while (!q.empty())
	{
		UndirectedGraphNode* n = q.front();
		q.pop();
		std::vector<UndirectedGraphNode*> neighbor = n->neighbors;
		for (int i = 0; i < neighbor.size(); ++i)
		{
			if (!visit[neighbor[i]])
			{
				q.push(neighbor[i]);
				visit[neighbor[i]] = true;
				t.push_back(neighbor[i]->label);
			}
		}
	}
}
std::vector<std::vector<int>> connectedSet(std::vector<UndirectedGraphNode*>& nodes)
{
	std::vector<std::vector<int>> result;
	std::unordered_map<UndirectedGraphNode*, bool> visit;
	for (int i = 0; i < nodes.size(); ++i)
		visit[nodes[i]] = false;

	for (int i = 0; i < nodes.size(); ++i)
	{
		if (!visit.at(nodes[i]))
		{
			std::vector<int> t;
			bfs(nodes[i], visit, t);
			sort(t.begin(), t.end());
			result.push_back(t);
		}
	}
	return result;
}