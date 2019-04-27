#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
//栈的应用：括号匹配
//括号匹配：
/*
依次遍历字符串中的每一个字符
如果是左括号
压栈
如果是右括号
判断当前栈是否为空栈
右括号多于左括号		return false

取出栈顶括号（左括号）
拿左括号和右括号进行匹配
如果不匹配				return false
弹出栈顶的左括号

如果栈里还有左括号，左括号多		return false

return true	
*/

bool isValid(string s)
{
	stack<char> stack_ch;
	int size = s.size();    // 返回字符串的长度
	for (int i = 0; i < size; i++)
	{
		char ch = s[i];
		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			stack_ch.push(ch);
			break;
		case ')':
		case ']':
		case '}':{
					 if (stack_ch.empty())
					 {
						 return false;
					 }
					 char left = stack_ch.top();
					 if (!((left == '(' && ch == ')')  //右括号多于左括号	
						 || (left == '[' && ch == ']')
						 || (left == '{' && ch == '}'))) 
					 {

						 return false;
					 }
					 stack_ch.pop();
					 break;
				 }
		default:
			break;
		}
		if (!stack_ch.empty()) {
			return false;
		}
		else {
			return true;
		}
	}
}

//2. 用队列实现栈
class MyStack {
public:
	queue<int>  q;  // 成员变量

	/*将元素x推入堆栈。*/
	void push(int x) {
		q.push(x);
	}

	/*删除堆栈顶部的元素并返回该元素。*/
	int pop() {
		int size = q.size() - 1;
		for (int i = 0; i < size; i++) {
			int data = q.front();
			q.pop();
			q.push(data);
		}

		int d = q.front();
		q.pop();
		return d;
	}

	/*获取顶部元素。*/
	int top() {
		int size = q.size() - 1;
		for (int i = 0; i < size; i++) {
			int data = q.front();
			q.pop();
			q.push(data);
		}

		int d = q.front();
		q.pop();
		q.push(d);

		return d;
	}

	/*返回堆栈是否为空*/
	bool empty() {
		return q.empty();
	}
};

//3.用栈实现队列。
class MyQueue {
public:
	stack<int>	left;
	stack<int>	right;

	/*将元素x推到队列的后面。*/
	void push(int x) {
		right.push(x);
	}

	/*从队列前面移除元素并返回该元素。*/
	int pop() {
		if (left.empty()) {
			int size = right.size();
			for (int i = 0; i < size; i++) {
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}

		int v = left.top();
		left.pop();
		return v;
	}

	/*获取front元素。*/
	int peek() {
		if (left.empty()) {
			int size = right.size();
			for (int i = 0; i < size; i++) {
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}

		int v = left.top();
		return v;
	}

	/*返回队列是否为空。*/
	bool empty() {
		return left.empty() && right.empty();
	}
};


//4. 实现一个最小栈。
class MinStack {
public:
	stack<int>	normal;
	stack<int>	min;

	void push(int x) {
		normal.push(x);
		if (min.empty() || x <= min.top()) {
			min.push(x);
		}
		else {
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};


//5. 设计循环队列
class MyCircularQueue {
public:
	int *array;
	int capacity;
	int size;
	int front;	// 队首下标
	int rear;	// 队尾下标

	/*在这里初始化数据结构。将队列的大小设置为k. */
	MyCircularQueue(int k) {
		array = new int[k];
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}

	/*在循环队列中插入一个元素。如果操作成功，返回true。*/
	bool enQueue(int value) {
		if (size == capacity) {
			return false;
		}

		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/*从循环队列中删除一个元素。如果操作成功，返回true。*/
	bool deQueue() {
		if (size == 0) {
			return false;
		}

		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/*从队列中获取前端项。*/
	int Front() {
		return array[front];
	}

	/*从队列中获取最后一项。*/
	int Rear() {
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/**检查循环队列是否为空。*/
	bool isEmpty() {
		return size == 0;
	}




	/*检查循环队列是否已满。*/
	bool isFull() {
		return size == capacity;
	}
};