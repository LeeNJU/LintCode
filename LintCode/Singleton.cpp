//��Ŀ��������C++ʵ�ֵ���ģʽ
//�ⷨ���������캯��private��instance����Ϊ��̬��instance�����ʼ��Ϊnull
class Solution 
{
private:
	static Solution* instance;
	Solution() {}
public:
	/**
	* @return: The same instance of this class every time
	*/

	static Solution* getInstance() 
	{
		if (instance == nullptr)
			instance = new Solution();
		return instance;
	}
};
Solution* Solution::instance = nullptr;