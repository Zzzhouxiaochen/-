//5. 熟悉队列的概念以及特性
//6. 熟悉循环队列，并分析循环队列如何判断队列满
//7. 实现队列的以下基本操作

typedef QNode* QDataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 链式结构：表示队列 
typedef struct QNode
{
	struct QNode* pNext;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode *head;		// 链表的第一个结点
	QNode *last;		// 链表的最后一个结点
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	q->head = q->last = NULL;
}

// 队尾入队列   //入队列
void QueuePush(Queue* q, QDataType data)
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->pNext = NULL;
	if (q->head == NULL)
	{
		q->head = node;
		q->last = node;
	}
	else
	{
		q->last->pNext = node;
		q->last = node;
	}
}

// 队头出队列   //出队列
void QueuePop(Queue* q)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node = q->head;
	free(q->head);
	q->head = node;

	// last 有没有可能也需要变更
	if (q->head == NULL) {
		q->last = NULL;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	return q->head->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->last->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	int size;
	for (QNode* c=q->head ; c !=NULL; c=c->pNext)
	{
		size++;
	}
	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->head == NULL)
		return 1;
	else
		return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* node;
	for ( node =q->head; node !=NULL; node=node->pNext)
	{
		free(node);
	}
	q->head = NULL;
	q->last = NULL;
}