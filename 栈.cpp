#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1. 熟悉栈的概念以及特性
//2. 数据结构中栈与程序中栈有什么不同？
//3. 实现栈的以下接口：
typedef int SDataType;
typedef struct Stack
{
	SDataType* array;
	int capacity;
	int top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->capacity = 0;
}

// 入栈 
void StackPush(Stack* ps, SDataType data)
{
	ps->array[ps->capacity++] = v;
}

// 出栈 
void StackPop(Stack* ps)
{
	ps->capacity--;
}

// 获取栈顶元素 
SDataType StackTop(Stack* ps)
{
	ps->top = ps->array[ps->capacity - 1];
	return ps->top;
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->capacity;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return !ps->capacity;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	ps->capacity;
}
//4. 栈的应用：括号匹配、逆波兰表达式、栈与递归
