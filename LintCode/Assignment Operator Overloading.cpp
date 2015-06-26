#include<iostream>
//题目描述：完成赋值操作符的重载，类中含有指针
//解法描述：先判断两个对象是否相等，然后删除该指针指向的对象，依次赋值
class Solution 
{
public:
	char *m_pData;
	Solution() 
	{
		this->m_pData = nullptr;
	}
	Solution(char *pData) 
	{
		this->m_pData = pData;
	}

	// Implement an assignment operator
	Solution operator=(const Solution &object) 
	{
		if (this != &object) //两个对象必须不同
		{
			delete m_pData; //删除原有对象
			m_pData = nullptr;
			if (object.m_pData) //在不为null的情况下，依次赋值
			{
				int length = strlen(object.m_pData);
				m_pData = new char[length];
				for (int i = 0; i < length; ++i)
					m_pData[i] = object.m_pData[i];
			}
		}
		return *this;
	}
};