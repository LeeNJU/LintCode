#include<vector>
#include<string>

//��Ŀ���������������ַ���������������ַ���������Ӵ��ĳ���
//�ⷨ��������ά��̬�滮�����A[i] == B[j],��ôdp[i][j] = dp[i - 1][j - 1] + 1,����dp[i][j] = 0;��һ������������������г��ֵ���󳤶ȣ�
//ע��dp[i][j]��ʾA[0-i]��B[0-j]��������Ӵ��ĳ��ȣ����ǲ�����ȫ��ȷ��������dp[i][j] = 0�Ĳ�����ǰ���ַ����ĳ��Ȳ�û�д��ݵ����棬���dp[A-1][B-1]
//������ʾA��B��������Ӵ��ĳ��ȣ�������Ҫһ����������¼��󳤶�

int longestCommonSubstring(std::string &A, std::string &B) {
	std::vector<std::vector<int>> t(A.size() + 1, std::vector<int>(B.size() + 1, 0));
	int max_length = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			if (A[i] == B[j])
				t[i + 1][j + 1] = t[i][j] + 1;
			else
				t[i + 1][j + 1] = 0;
			if (t[i + 1][j + 1] > max_length)
				max_length = t[i + 1][j + 1];
		}
	}
	return max_length;
}