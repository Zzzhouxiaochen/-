#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1. ��Ϥջ�ĸ����Լ�����
//2. ���ݽṹ��ջ�������ջ��ʲô��ͬ��
//3. ʵ��ջ�����½ӿڣ�
typedef int SDataType;
typedef struct Stack
{
	SDataType* array;
	int capacity;
	int top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->capacity = 0;
}

// ��ջ 
void StackPush(Stack* ps, SDataType data)
{
	ps->array[ps->capacity++] = v;
}

// ��ջ 
void StackPop(Stack* ps)
{
	ps->capacity--;
}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps)
{
	ps->top = ps->array[ps->capacity - 1];
	return ps->top;
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->capacity;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return !ps->capacity;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	ps->capacity;
}
//4. ջ��Ӧ�ã�����ƥ�䡢�沨�����ʽ��ջ��ݹ�
