#include<vector>
#include<unordered_map>
#include<queue>
#include"Node.h"

//��Ŀ����������һ������ͼ���ҵ�������ͨ��ͼ�ĸ���
//�ⷨ����������ÿһ���ڵ㣬����ýڵ�û�б����ʹ�����ô���й��ѣ��ҵ�һ����ͨ��ͼ��������ͼ�еĵ���б�ǡ�
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