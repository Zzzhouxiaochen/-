#include<stdio.h>
#include<stdlib.h>



typedef int DataType;

typedef struct SeqList
{
	DataType* array; // 保存顺序表中有效元素个数 
	int capacity; // 空间总大小 
	int size; // 有效元素个数 
}SeqList, *PSeqList;

void SeqListInit(PSeqList ps)
{

	// 开辟空间
	// 设置容量 和 size
	ps->capacity = 10;
	ps->array= (int *)malloc(sizeof(DataType)* ps->capacity);
	ps->size = 0;
}


void SeqListDestroy(PSeqList ps)
{
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;

}
// 尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	ps->array[ps->size] = data;
	ps->size++;
}
// 尾删 
void SeqListPopBack(PSeqList ps)
{
	ps->size--;
}
// 头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	for (int i = ps->size; i >= 1; i--)  //i是空间下标
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = data;
	ps->size++;
}
// 头删 
void SeqListPopFront(PSeqList ps)
{
	for (int i = 1; i <= ps->size-1; i++)  //i是空间下标
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	if (pos < 0 || pos >= ps->size)
	{
		printf("你插入的位置不存在\n");
	}
	else
	{
		for (int i = ps->size; i >= pos; i--)  //i空间下标
		{
			ps->array[i] = ps->array[i - 1];
		}
		ps->array[pos] = data;
		ps->size++;
	}

}

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	for (int i = pos+1; i <= ps->size; i++)  //i空间下标
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

// 检测data释放在顺序表中 
int SeqListFind(PSeqList ps, DataType data)   //i空间下标
{
	for (int i = 1; i <= ps->size; i++)
	{
		if (ps->array[i - 1] == data)
		{
			return 1;
		}
	}
}
// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList ps, DataType data)   //i空间下标
{
	for (int i = 1; i <= ps->size; i++)
	{
		if (ps->array[i - 1] == data)
		{
			ps->array[i - 1] = ps->array[i];
			ps->size--;
			break;
		}
	}
}
// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data)   //i空间下标
{
	while (1)
	{
		for (int i = 1; i <= ps->size; i++)
		{
			if (ps->array[i - 1] == data)
			{
				ps->array[i - 1] = ps->array[i];
				ps->size--;
				continue;
			}
		}
	}
}
// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps)   //i空间下标
{
	return ps->size;
}
// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)   //i空间下标
{
	return ps->capacity;
}
// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)   //i空间下标
{
	if (ps->size == 0)
		return 0;
}
// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)  //i空间下标
{
	return ps->array[0];
}
// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)   //i空间下标
{
	return ps->array[ps->size - 1];
}
