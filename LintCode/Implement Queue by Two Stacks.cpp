#include<stack>
//题目描述：用两个栈来实现一个队列
//解法描述：

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

	int pop() //如果stack2是空的，那么把stack2的元素push到stack2中，如果stack2非空，直接弹出stack2的栈顶元素
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

	int top()  //如果stack2是空，把stack1的元素push到stack2中
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