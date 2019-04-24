//顺序表
#define MAX 1000
#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct
{
	datatype  elem[MAX];  //定义数组
	int last;  //最后一个元素的位置  last 是最后一个元素的下标  last +1确定数组长度  是下标
}SeqList;

//数组的长度和 线性表长度不一样    
//数组长度是存放线性表的存储空间长度 分配后值不变 
//线性表长度是元素个数，它随着线性表的插入删除操作会有变化
//注意区分数据元素位序和下标   如a0的位序是1，下标是0

SeqList L; //定义一个顺序表
//表长：L.last+1  数据是a1~an  分别存放a[0]到a[L.last]


SeqList* LP;  //LP是一个指针变量
//存储空间的设定
LP = (SeqList*)malloc(sizeof(SeqList));   //LP中放的是顺序表的地址
//表长：(*LP).last+1 或者 LP->last+1




//插入操作
//步骤：1.ai~an依次往后移动一个
//	  2.插入数据
//	  3.改变last指向最后一个元素 也就是改变表长
//注意：判断表是否为满；插入位置的有效性；数据移动方向；修改last
void charu(SeqList* Lp, int i,datatype x)
{
	//判满
	if (Lp->last == MAX - 1) 
		printf("表满！\n");
	return;

	
	//判断合理性
	int i;	  //i是位置
	if (i<1 || i>Lp->last)
		printf("位置错误！");
	return;

	//插入数据
	int j;
	for (j = Lp->last; j >= i - 1; j--)  //移位置 last是下标
	{
		Lp->elem[j+1] = LP->elem[j];   //改变位置所以 数组下标加一
	} 
	Lp->elem[i - 1] = x;   //插入数据
	Lp->last++;
	
}
//顺序表插入操作时间复杂度是O(n);


//删除操作
//删除第i个元素

//步骤：
//1.将ai~an顺序上移
//2.改变last指针长度
//注意：
//表空不能删除；删除第i个元素，保证有效性；注意移动方向
int shanchu(SeqList* Lp, int i)  
{
	//判断有效性，空表
	int j;
	if (i<1 || i>Lp->last + 1)
	{
		printf("不存在i元素！");
		return(0);
	}

	//移动位置
	for ( j = i; j <Lp->last ; j++)
	{
		Lp->elem[j - 1] = Lp->elem[j];
	}
	Lp->last--;
	return(1);
}
//时间复杂度O(n)



//顺序表的实例
//两个线性表La,Lb分别表示集合a,b 要求新的集合a=a U b  假设所有元素都是属于整型数据
//思路：扩展La线表 Lb中逐步取出元素，与La比较，没有的元素进行插入操作，因为无序性，不需要移动操作
void jihe(SeqList* La, SeqList Lb)
{
	int i, j, La_len, Lb_len;
	datatype e;
	La_len = La->last;
	Lb_len = Lb.last;
	for ( i = 0; i < Lb_len; i++)
	{
		e = Lb.elem[i];
		j = 0;
		while (j <= La_len&&e != La->elem[j])j++;
			if (j>La_len)
			if (La_len < MAX - 1)
				La->elem[++(La->last)] = e;
	}
}


//两个顺序表由小到大升序   合并之后还是升序
//思路：一次扫描a,b。扫描中较小的数放到c中,直到一个表扫描结束，把剩余的数全给c。
//c的容量要足够容纳a, b。设两个指针i, j分别指向a, b元素，若a.elem[i]>b.elem[j], 将b.elem[j]插入
//反之，a.elem[i]插入c中。

void hebingpaixu(SeqList A, SeqList B,SeqList* C)
{
	int i, j, k;
	//判断AB表不能为空
	while (A.last >= i && B.last >= j)
	{
		if (A.elem[i] < B.elem[j])
			C->elem[k++] = A.elem[i++];//将A中i指针指向的记录插入C中
		else
			C->elem[k++] = B.elem[j++];//将B中i指针指向的记录插入C中
	}
	while (i<=A.last)     //A剩余部分插入
		C->elem[k++] = A.elem[i++];
	while (i <= B.last)     //B剩余部分插入
		C->elem[k++] = B.elem[j++];
	
}










int main()
{
		

	system("pause");
	return 0;
}