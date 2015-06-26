#include<iostream>
//��Ŀ��������ɸ�ֵ�����������أ����к���ָ��
//�ⷨ���������ж����������Ƿ���ȣ�Ȼ��ɾ����ָ��ָ��Ķ������θ�ֵ
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
		if (this != &object) //����������벻ͬ
		{
			delete m_pData; //ɾ��ԭ�ж���
			m_pData = nullptr;
			if (object.m_pData) //�ڲ�Ϊnull������£����θ�ֵ
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