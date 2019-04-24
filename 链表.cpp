typedef struct Node    //结点
{
	int data;
	struct Node* next;
}Node;

typedef struct Header   //头结点
{
	int length;
	struct Node* next; //指向第一个
}pHead;


pHead * creat() //创建链表
{
	pHead* ph = (pHead*)malloc(sizeof(pHead));  //分配空间
	ph->length = 0;    //头节点初始化
	ph->head = NULL;
	return ph;    //返回头节点地址
}

int Size(pHead* ph)     //求列表大小
{
	if (ph == NULL)
		return;
	return ph->length;
}

int Insert(pHead* ph,int pos,int v)   //插入
{
	if (ph == NULL || pos<0 || pos>ph->length)  //判断和理性
		return;

	//插入元素时候要判断位置
	Node* valu = (Node*)malloc(sizeof(Node));//创建一个新的结点来放数据
	valu->data = v;
	Node* cur = ph->next; //当前指针指向头节点的next
	if (pos == 0)  //头插   //位置判断
	{
		ph->next = valu;
		valu->next = cur;
	}
	else
	{
		for (int i = 1; i < pos; i++)  //寻找插入位置 前一个结点的next
		{
			cur = cur->next;
		}
		valu->next = cur->next;   //插入工作
		cur->next = valu;  
	}
	ph->length++;
	return 1;
}


Node* find(pHead* ph, int v)   //查找
{
	if (ph == NULL)  //判空
		return NULL;
	
	//遍历查找元素
	Node* cur = ph->next;  //保存next
	while (cur->next != NULL)
	{
		if (cur->data == v)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


Node* del(pHead* ph,int v)
{
	if (ph == NULL)
		return NULL;
	Node* cur = find(ph, v);
	if (cur == NULL)
		return NULL;

	Node* pRe = ph->next;  //当前节点
	Node* pCur = NULL;
	if (pRe->data == v)  //头删
	{
		ph->next = pRe->next;
		ph->length--;
		return pRe;
	}
	else
	{
		for (int i = 0; i < ph->length; i++) //遍历链表
		{
			pCur = pRe->next;
			if (pCur->data == v)  //删除
			{
				pRe->next = pCur->next;  //删除
				ph->length--;
				return pCur;
			}
			pRe = pRe->next;
		}
	}
}


//销毁链表，即将结点释放
void Destory(pHead* ph)
{
	Node* pCur = ph->next;
	Node* pTemp;
	if (ph == NULL)
		return;
	while (pCur->next != NULL)
	{
		pTemp = pCur->next;
		free(pCur);
		pCur = pTemp;
	}
	ph->length = 0;
	ph->next = NULL;
}
