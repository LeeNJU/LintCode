#include<vector>
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(nullptr){}
};

struct DirectedGraphNode {
	int label;
	std::vector<DirectedGraphNode *> neighbors;
	DirectedGraphNode(int x) : label(x) {};
};