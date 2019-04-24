
typedef struct Node
{
	int value;
	struct Node *next;
}Node;

//链表的合并
Node * hebing(Node* 11,Node* 12)
if (11 == NULL)
	return 12;
if (12 == NULL)
	return 11;

ListNode* c1 = 11;
ListNode* c2 = 12;
struct ListNode* result = NULL;  //链表第一个节点地址   是定义了一个新链表
//用于return 存head地址  返回后只要拍好了依次会走一遍
struct ListNode* tail = NULL;//链表的最后一个节点
while (p1 != NULL&&p2 != NULL)
{
	if (p1->val <= c2->val)
	{
		//取11链表节点
		if (tail == NULL)
		{
			result = tail = c1;
		}
		else
		{
			tail->next = c1;//节点 先表示给指向从c1
			tail = c1; //c1的值给tail
		}
		c1 = c1->next;
	}
	else
	{
		//取12链表节点

	}
	if (c1 != NULL)
	{

		tail->next = c1;
	}
	else
	{
		tail->next = c2;
	}
}





//逆置链表
struct Node* fanzhuan(Node *head)   //三指针
{
	Node* p1 = NULL;
	Node* p2 = head;
	Node* p3 = head->next;

	if (p2 != NULL)
	{
		Node* next = p2->next;

		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 == NULL)
		{
			p3 = p3->next;
		}
	}

	return p1;
}


struct Node* fanzhuan(Node *head) //头山头查
{
	Node* p1 = NULL;
	Node* p2 = head;

	if (p2 != NULL)
	{
		Node* p3 = p2->next;

		p2->next = p1;
		p1 = p2;
		p2 = p3;

	}
	return p1;

}

//head是列表的第一个结点，node要插入的结点

//头插
void toucha(Node* head, Node* node)
{
	node->next = head;
	head = node;
}

//头删
void toushan(Node* head, Node* node)
{
	head = head->next;
}
//尾插
void weicha(Node* head, Node* node)
{

}

//尾删
void weishan(Node* head, Node* node)
{

}



//判断两个列表是否相交
//判断相交的位置，求相交点






//判断链表是否带环
//两个指针的速度关系，快的一定可以追的上慢的 在跑圈情况
struct ListNode *fast = head;
struct ListNode *slow = head;
if (fast == slow)
{
	return ture;
}

//求入口点





//复制复杂链表





//顺序表头查

typedef struct SeqList
{
	int *array;
	int size;
	int capacity;
}Seqlist;


void toucha(Seqlist* s, int y)
{
	s->array = (SeqList*)malloc(sizeof(SeqList));
	s->capacity = 100;

	int i;//i是数组下标
	for (i = s->size; i >0 ; i--)
	{
		s->array[i ] = s->array[i-1];
		
	}
	s->array[0] = v;
	s->size++;



	if (s->size == s->capacity)
	{
		//开辟新空间
		int * newarray = (int*)malloc(sizeof(int)*s->capacity * 2);
		for (int i = 0; i < s->size; i++)
		{
			newarray[i] = s->array[i];
		}
		free(s->array);

		s->array = newarray;

		s->capacity = s->capacity * 2;
	}
}