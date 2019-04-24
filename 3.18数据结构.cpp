#pragma once

/*
// 静态顺序表（顺序表大小是固定的（编译期间决定的（写死在代码里的
typedef struct SeqList {
int array[100];	// 容量是 100
int size;		// 顺序里有效数据个数
// 同时也表示从后数下一个可用位置的下标
}	SeqList;

*/

typedef int SLDataType;

// 动态顺序表（在程序运行期间可以动态控制容量的大小
typedef struct SeqList {
	SLDataType *array;		// 指向 堆上空间，存放数据
	int capacity;	// 容量
	int size;		// 有效个数
}	SeqList;

// 服务列表，函数列表

// 创建 | 销毁
void SeqListInit(SeqList *pSeqList);

void SeqListDestroy(SeqList *pSeqList);

// 增 删 查 改
// 尾插
void SeqListPushBack(SeqList *pSeqList, SLDataType value);

// 头插
void SeqListPushFront(SeqList *pSeqList, SLDataType value);






void SeqListInit(SeqList *pSeqList) {
	// 期望传递进来的是一个变量的地址
	// 变量的地址肯定不是 NULL
	assert(pSeqList != NULL);

	// 开辟空间
	// 设置容量 和 size
	pSeqList->capacity = 10;
	pSeqList->array
		= (int *)malloc(sizeof(SLDataType)* pSeqList->capacity);
	pSeqList->size = 0;
}


void SeqListDestroy(SeqList *pSeqList) {
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);

	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

void SeqListPushBack(SeqList *pSeqList, SLDataType value) {
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}


void SeqListPushFront(SeqList *pSeqList, SLDataType value) {
	// i 是空间的下标
	for (int i = pSeqList->size; i >= 1; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}

	pSeqList->array[0] = value;
	pSeqList->size++;
}




void SeqListInsert(SeqListInsert *s, int pos, DT v)   //中间插入
{
	for (int i = pSeqList->size; i >= pos; i--)
	{
		pSeqList->array[i] = pSeqList->array[i-1]; //i是空间下标
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;  //复杂程度O（n）
}

	SLDataType *array;		// 指向 堆上空间，存放数据
	int capacity;	// 容量
	int size;		// 有效个数
}	SeqList;

void SeqListPopBack() //尾删
{
	array(pSeqList->size > 0);
	ps->size--;
}

void SeqListPophead()  //i是空间下标  //头删除
{
	for (int i = 0; i<= pSeqList->size-2; i++)
	{
		pSeqList->size[i] = pSeqList->size[i + 1];
	}
	pSeqList->size--;
}

void SeqListzhong()  //数组下标删除
{
	for (int i = 0; i < pSeqList->size; i++)
	{
		pSeqList->array[i - 1] = pSeqList->array[i];
	}
	pSeqList->size--;
}

void SeqListcha()//查找
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] = value)
			return array[i];
	}
}

void xiugai()
{
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = value;
}


//扩容  通常扩容大小事平常大小的两倍

void kuorong()
{
	if (ps->size < ps->capacity)  //小于容量
		return;

	int newcapacity = ps->capacoty * 2;


}
int main() {
	SeqList	seqlist;

	SeqListInit(&seqlist);
}


int i, j;
for ( i = 0,j=0; i < ps->size; i++)
{
	if (ps->array[i] != value)
		ps->array[j = ps->array[i];
	j++;
}



//链表  重点
//定义的不是链表的结构体 而是链表中一个节点的结构体
typedef int SListDatatype;

typedef struct ListNode
{
	SListDatatype value; //保存的值
	struct List *next;//下一个节点的结构体
}Node;

//地址{value,next}


typedef struct SList
{
	Node *first;    //node 的第一个数据的地址  first =NULL；链表是空的
}SList;

void SListInit(SList *s)    //初始化
{
	assert(s != NULL);
	s->first = NULL;

}

void test()
{
	SList list;
	SListInit();

}
//头查头山 O1   尾插尾删 On

//头插   
void SListPushFrount(SList *s, SLDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node)));
	node->value = v;
	node->next = node->first;
	node->first = node;

}

//尾插
void weicha(SList *s, SLDataType v)
{  
	//链表为空的情况
	if (s->first == NULL)
	{
		s->first = node;
		return;
	}
	
	//找最后一个节点
	Node *cur = s->first;
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = node;//最后一个节点一定为空
}





void weicha(SList *s,SLDataType v)
{
	
	if (s->first == NULL)
		s->first = node;


	Node *cur = s->first;
	while (cur->next != NULL)
	{
		cur= cur->next;
	}
	cur->next = node;
}


//头删
void toushan(SList *s)
{
	assert(s != NULL);
	assert(s->first != NULL);
	Node *next = s->first->next;
	free(s->first);
	s->first = next;
}


void weishan(SList* s)
{

	assert(s != NULL);
	assert(s->first != NULL);

	if (s->first->next == NULL)
		free(s->first);
	s->first = NULL; 
		return;

		Node *cur;
		for ( cur = s->first; cur->next->next!=NULL; cur++)
		{
			free(cur->next);
			cur->next = NULL;
		}

}


//顺序表增删改查 头删 头插  中间插入 中间删除  扩容 时间复杂度   
//链表 头插 头删 尾插 尾部删除






