//单链表：
//它放一个数据，和下一个数据的地址 这两个部分组成一个结点，每个元素都是如此，放数据的地方是data，放地址的地方是next
//单链表是由头指针唯一确定的 
//描述如下：
typedef struct node
{
	elemtype data; //数据
	struct node *next;  //指针
}LNode,*LinkList;
LinkList H; //定义头指针 
//头指针为NULL  表示空链表，即H==NULL为真  

//通常在第一个结点之前加上头结点，头结点数据域可以不存放任何数据，也可以存放节点个数信息 
//空线表是H->next=NULL为真，非空线表是H->next指向下一个结点的地址


//不带节点的链表是L == NULL          带节点的L->next = NULL
//链表的第一个元素由L指向          第一个元素由L->next指向
//第一个元素的插入删除 与其他不同    插入删除是统一的
//
//对于带头结点的单链表L
//L->next = NULL  表示一个单链表为空链表 长度为0；
//不是空表则是通过头指针访问界定啊，找到索要访问的信息 例如：p = L->next指向表中的第一个结点a1；即p->data = a1;
//而p->next->data=a2
//可以用malloc函数来实现内存空间：
//p = (LinkList)malloc(sizeof(LNode));
//free(p)实现释放



//单链表的基本运算的实现：
//1.建立单链表
//（1）头插法建立单链表
//链表是动态存储的，因此建立链表从空表开始，没读入一个数据申请一个结点 然后插入链表头部。

//代码如下：
LinkList CreatFromHead()
{
	LinkList L;  //建立链表L
	LNode *s;
	char c;
	int flag = 1;//链表结束标志位  由￥就结束建表
	L = (LinkList)malloc(sizeof(LNode));//分配存储空间
	L->next = NULL;  //链表初始化
	while (flag)   //标志位起作用
	{
		c = getchar();
		if (c != '￥')
		{
			s = (LinkList)malloc(sizeof(LNode));//为新进的数据进行分配存储空间
			s->data = c;  //数据域赋值
			s->next = L->next;//将s插入到第一个元素之前
			L->next = s;
		}
		else
			flag = 0;
	}
}


//尾部插入结点建立单链表
//利用尾插方法，但是需要加一个新的指针r 用来始终指向链表尾的尾部节点
//代码如下：

LinkList CreatFromHead()
{
	LinkList L;  //建立链表L
	LNode *s,*r;
	char c;
	int flag = 1;//链表结束标志位  由￥就结束建表
	L = (LinkList)malloc(sizeof(LNode));//分配存储空间
	L->next = NULL;  //链表初始化
	r = L;
	while (flag)   //标志位起作用
	{
		c = getchar();
		if (c != '￥')
		{
			s = (LinkList)malloc(sizeof(LNode));//为新进的数据进行分配存储空间
			s->data = c;  //数据域赋值
			r->next = s; //尾插
			r = s;// 依旧指向最后一个结点

		}
		else
		{
			flag = 0;
			r->next = NULL;//结束
		}
	}
	return L;
}
//注意：L和r的关系 L是单链表,r是指向尾节点的指针




//求链表长度
int ListLength(LinkList L)
{
	LinkList p;
	p = L;
	int j = 0;   //用来存放单链表的长度
	while (p->next!=NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}
//时间复杂度O(n)



//查找
//是否有结点值为e返回，若找到，返回首次找到值e的存储地址，否则NULL;

LinkList Locate(LinkList L, char e)
{
	LinkList p;
	p = L->next;  //从第一个比较
	while (p!=NULL&&p->data!=e)
	{
		p = p->next;
	}
	return p;
}//时间复杂度O（n）

//单链表插入操作
int InsList(LinkList L, int i, char e)
{
	LinkList pre, s;
	int k;
	pre = L; k = 0;
	while (pre!=NULL&&k=i-1)  //找到第i元素  使指针指向他
	{
		pre = pre->next;
		k = k + 1;
	}
	if (k!=1)
	{
		printf("插入错误！");
		return 0;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = c;
	s->next = pre->next;
	pre->next = s;
	return 1;
}



//删除操作
int DelList(LinkList L, int i, char *e)
{
	LinkList pre, s,r;
	int k;
	pre = L; k = 0;
	while (pre->next != NULL&&k = i - 1)  //找到第i元素  使指针指向他
	{
		pre = pre->next;
		k = k + 1;
	}
	if (k !=1- 1)
	{
		printf("插入错误！");
		return 0;
	}
	r = pre->next;
	pre->next = pre->next->next;
	*e = r->data;
	return 1;
}


//循环单链表  
//是最后一个指向开头 即p!=L 或者 p->next!=L

//单链表首位相连
LinkList merge(LinkList R1, LinkList R2)
{
	node *p;
	p = R1->next;  //保存R1首部地址
	R1->next = R2->next->next; // R1尾部和R2首部相连
	free(R2->next);
	R2->next = p;  //R2最后一个结点到头节点
	return R1;
} //时间复杂度O(1)




malloc和free 都是动态链表
//静态链表
