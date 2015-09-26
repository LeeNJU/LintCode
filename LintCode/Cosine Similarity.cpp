#include<vector>
//��Ŀ������������������A��B����ʾ������������cosine�����ԣ���A * B / (sqrt(A2) * sqrt(B2))�����A��B���Ϸ�������2
//�ⷨ����������ʽʵ�ּ���
double cosineSimilarity(std::vector<int> A, std::vector<int> B) 
{
	if (A.empty() || B.empty())
		return 2.0;

	double sum = 0, squareSumA = 0, squareSumB = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		sum += A[i] * B[i];
		squareSumA += A[i] * A[i];
		squareSumB += B[i] * B[i];
	}

	if (squareSumA == 0 || squareSumB == 0)
		return 2.0;

	return sum / (sqrt(squareSumA) * sqrt(squareSumB));
}