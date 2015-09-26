#include<vector>
//题目描述：给定两个数组A和B，表示两个向量，求cosine相似性，及A * B / (sqrt(A2) * sqrt(B2))，如果A和B不合法，返回2
//解法描述：按公式实现即可
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