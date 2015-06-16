#include"Node.h"
#include<algorithm>
#include<unordered_map>

//��Ŀ����������һ������ͼ�������ڵ㣬�ж��������ڵ��Ƿ�����
//�ⷨ������ͼ�������������


bool dfs(DirectedGraphNode* s, DirectedGraphNode* t, std::unordered_map<DirectedGraphNode*, bool>& visited)
{
	if (s->label == t->label)
		return true;

	visited[s] = true;
	std::vector<DirectedGraphNode*> neighbors = s->neighbors;
	for (int i = 0; i < neighbors.size(); ++i)
	{
		if (!visited[neighbors[i]] && dfs(neighbors[i], t, visited)) //ע�������dfs�ݹ���ñ������������
			return true;
	}
	return false;
}

bool hasRoute(std::vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t)
{
	std::unordered_map<DirectedGraphNode*, bool> visited(graph.size());
	return dfs(s, t, visited);
}
