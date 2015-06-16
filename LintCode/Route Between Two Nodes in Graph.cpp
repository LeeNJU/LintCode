#include"Node.h"
#include<algorithm>
#include<unordered_map>

//题目描述：给定一个有向图和两个节点，判断这两个节点是否相连
//解法描述：图的深度优先搜索


bool dfs(DirectedGraphNode* s, DirectedGraphNode* t, std::unordered_map<DirectedGraphNode*, bool>& visited)
{
	if (s->label == t->label)
		return true;

	visited[s] = true;
	std::vector<DirectedGraphNode*> neighbors = s->neighbors;
	for (int i = 0; i < neighbors.size(); ++i)
	{
		if (!visited[neighbors[i]] && dfs(neighbors[i], t, visited)) //注意这里的dfs递归调用必须放在条件中
			return true;
	}
	return false;
}

bool hasRoute(std::vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t)
{
	std::unordered_map<DirectedGraphNode*, bool> visited(graph.size());
	return dfs(s, t, visited);
}
