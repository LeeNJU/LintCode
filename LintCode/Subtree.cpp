#include"Node.h"
//��Ŀ����������������T1��T2��T1���ϰ�����ڵ㣬T2�м��ٸ��ڵ㣬�ж�T2�ǲ���T1������
//�ⷨ�������ݹ飬ע��������п��ܰ�����ͬ��Ԫ�أ���T1��Ԫ�غ�T2��Ԫ����ȵ�ʱ��Ҫ�ݹ��ж������������Ƿ���ȣ�������ȣ�Ҫ
//         �����ݹ��ж��Ƿ�������

bool isSame(TreeNode* T1, TreeNode* T2) //�Ƿ�����ȵ���
{
	if (T1 == nullptr && T2 == nullptr)
		return true;
	if (T1 != nullptr && T2 != nullptr && T1->val == T2->val)
		return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
	return false;
}
bool isSubtree(TreeNode *T1, TreeNode *T2) 
{
	if (T2 == nullptr)
		return true;
	if (T1 == nullptr)
		return false;

	bool result = false;
	if (T1->val == T2->val) //ֵ���Ҫ�ж��Ƿ�����ȵ���
		result = isSame(T1, T2);

	if (!result) //������ȵ�����Ҫ�����ж�
		result = isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
	return result;
}