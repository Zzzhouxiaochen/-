//5. ��Ϥ���еĸ����Լ�����
//6. ��Ϥѭ�����У�������ѭ����������ж϶�����
//7. ʵ�ֶ��е����»�������

typedef QNode* QDataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ��ʽ�ṹ����ʾ���� 
typedef struct QNode
{
	struct QNode* pNext;
	QDataType data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode *head;		// ����ĵ�һ�����
	QNode *last;		// ��������һ�����
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->head = q->last = NULL;
}

// ��β�����   //�����
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

// ��ͷ������   //������
void QueuePop(Queue* q)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node = q->head;
	free(q->head);
	q->head = node;

	// last ��û�п���Ҳ��Ҫ���
	if (q->head == NULL) {
		q->last = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	return q->head->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->last->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	int size;
	for (QNode* c=q->head ; c !=NULL; c=c->pNext)
	{
		size++;
	}
	return size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->head == NULL)
		return 1;
	else
		return 0;
}

// ���ٶ��� 
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