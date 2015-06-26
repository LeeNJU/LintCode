//题目描述：用C++实现单键模式
//解法描述：构造函数private，instance必须为静态，instance必须初始化为null
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