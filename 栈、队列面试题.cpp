#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
//ջ��Ӧ�ã�����ƥ��
//����ƥ�䣺
/*
���α����ַ����е�ÿһ���ַ�
�����������
ѹջ
�����������
�жϵ�ǰջ�Ƿ�Ϊ��ջ
�����Ŷ���������		return false

ȡ��ջ�����ţ������ţ�
�������ź������Ž���ƥ��
�����ƥ��				return false
����ջ����������

���ջ�ﻹ�������ţ������Ŷ�		return false

return true	
*/

bool isValid(string s)
{
	stack<char> stack_ch;
	int size = s.size();    // �����ַ����ĳ���
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
					 if (!((left == '(' && ch == ')')  //�����Ŷ���������	
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

//2. �ö���ʵ��ջ
class MyStack {
public:
	queue<int>  q;  // ��Ա����

	/*��Ԫ��x�����ջ��*/
	void push(int x) {
		q.push(x);
	}

	/*ɾ����ջ������Ԫ�ز����ظ�Ԫ�ء�*/
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

	/*��ȡ����Ԫ�ء�*/
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

	/*���ض�ջ�Ƿ�Ϊ��*/
	bool empty() {
		return q.empty();
	}
};

//3.��ջʵ�ֶ��С�
class MyQueue {
public:
	stack<int>	left;
	stack<int>	right;

	/*��Ԫ��x�Ƶ����еĺ��档*/
	void push(int x) {
		right.push(x);
	}

	/*�Ӷ���ǰ���Ƴ�Ԫ�ز����ظ�Ԫ�ء�*/
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

	/*��ȡfrontԪ�ء�*/
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

	/*���ض����Ƿ�Ϊ�ա�*/
	bool empty() {
		return left.empty() && right.empty();
	}
};


//4. ʵ��һ����Сջ��
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


//5. ���ѭ������
class MyCircularQueue {
public:
	int *array;
	int capacity;
	int size;
	int front;	// �����±�
	int rear;	// ��β�±�

	/*�������ʼ�����ݽṹ�������еĴ�С����Ϊk. */
	MyCircularQueue(int k) {
		array = new int[k];
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}

	/*��ѭ�������в���һ��Ԫ�ء���������ɹ�������true��*/
	bool enQueue(int value) {
		if (size == capacity) {
			return false;
		}

		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/*��ѭ��������ɾ��һ��Ԫ�ء���������ɹ�������true��*/
	bool deQueue() {
		if (size == 0) {
			return false;
		}

		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/*�Ӷ����л�ȡǰ���*/
	int Front() {
		return array[front];
	}

	/*�Ӷ����л�ȡ���һ�*/
	int Rear() {
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/**���ѭ�������Ƿ�Ϊ�ա�*/
	bool isEmpty() {
		return size == 0;
	}




	/*���ѭ�������Ƿ�������*/
	bool isFull() {
		return size == capacity;
	}
};