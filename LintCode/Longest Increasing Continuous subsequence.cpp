#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬�ҵ���ĵ������еĳ��ȣ�����ĵ������п����Ǵ������ҵ�����Ҳ�����Ǵ����������
//�ⷨ��������̬�滮������ɨ�衣prev��cur�������㵱ǰһ�����������еĳ��ȣ�right_result����������ĳ���

int longestIncreasingContinuousSubsequence(std::vector<int>& A) {
	if (A.empty()) //�ж�Ϊ�յ����
		return 0;

	int prev = 1, cur = 1, right_result = 1;
	for (int i = 1; i < A.size(); ++i)//�ȼ���������ҵĽ��
	{
		if (A[i] >= A[i - 1]) //��ǰԪ�ر�ǰһ��Ԫ�ش���ôcurӦ�ü�1��prev��ֵ����Ϊcur��1ǰ��ֵ
		{
			cur = prev + 1;
			prev = cur;
		}
		else //��ǰԪ�ر�ǰһ��Ԫ��С��˵�����������ж��ˣ�cur��prev����Ϊ1
		{
			cur = 1;
			prev = 1;
		}
		right_result = std::max(right_result, cur);//right_result������
	}

	prev = cur = 1;
	int left_result = 1;
	for (int i = A.size() - 2; i >= 0; --i)
	{
		if (A[i] >= A[i + 1])
		{
			cur = prev + 1;
			prev = cur;
		}
		else
		{
			cur = prev = 1;
		}
		left_result = std::max(left_result, cur);
	}
	return std::max(left_result, right_result);
}