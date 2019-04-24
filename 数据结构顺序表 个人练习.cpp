//顺序表的定义初始化：
typedef struct SeqList
{
	int* array; //存数据
	int size; //实际长度
	int capacity;//容量
}SeqList;

//顺序表的基本操作：增删查改


//建立顺序表
void Creat(SeqList* p)  //传递首地址就不会为NULL
{
	
	p->capacity = 100;  //先设置容量
	p->array = (int*)malloc(sizeof(int) * p->capacity);//动态分布内存
	p->size == 0;//顺序表初始化
}


//增
//头查就是i=0
void zeng(SeqList* p,int pos,int v)
{
	int i; //i是位置下标
	for (i = p->size; i > 0; i--)  //从后往前移位置
	{
		p->array[i] = p->array[i - 1];
	}
	p->array[0] = v;//插入
	p->size++;//指向最后一个
}
//尾部插入


//删
//头删除 i=0
void toushan(SeqList* p)
{
	for (int i = 0; i <= p->size-2; i++)   //为什么减2
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--; 
}
//尾删除 i=p->size
void weishan(SeqList* p)
{

	p->size--;
}
//删除第i个 i=pov
void zhongjianshan(SeqList* p,int pov)  //pov删除特定的位置
{
	for (int i = pov; i <=p->size; i++)
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--;
}

//查
int cha(SeqList* p,int v)  //查找数据v
{
	for (int i = 0; i <=p->size; i++)  //i:是数组下标
	{
		if (p->size == v)
			return i;
	}
}

//改
void gai(SeqList* p,int pos,int v)
{
	p->array[pos] = v;
}

//扩容
void kuorong(SeqList* p)
{
	p->capacity = 100;  //先设置容量
	p->array = (int*)malloc(sizeof(int)*p->capacity);//分布内存

	if (p->size == p->capacity)  //开辟新空间
	{
		int * newarray = (int*)malloc(sizeof(int)* p->capacity * 2);
		for (int i = 0; i <= p->size; i++)   //移数据
		{
			newarray[i] = p->array[i];
		}
		free(p->array); //释放掉原来的空间
		p->array = newarray;  //将指针中的地址改变
		p->capacity = p->capacity * 2;
	}
}