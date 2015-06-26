#include<stack>
//��Ŀ������������ջ��ʵ��һ������
//�ⷨ������

class Queue 
{
public:
	std::stack<int> stack1;
	std::stack<int> stack2;

	Queue() 
	{
	}

	void push(int element) 
	{
		stack1.push(element);
	}

	int pop() //���stack2�ǿյģ���ô��stack2��Ԫ��push��stack2�У����stack2�ǿգ�ֱ�ӵ���stack2��ջ��Ԫ��
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int element = stack2.top();
		stack2.pop();
		return element;
	}

	int top()  //���stack2�ǿգ���stack1��Ԫ��push��stack2��
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();
	}
};