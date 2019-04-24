typedef struct ListNode
{
	int value;
	struct ListNode *next;
}Node;


typedef struct SList {
	Node *first;	// Node *head;
}	SList;


//初始化  
SList* s;
s->first = NULL;   


//插入
//头插
void tou(SList* s, int v)  //定义头指针  SList 类型
{
	Node* node = (Node*)malloc(sizeof(Node)); //创建结点分配空间
	node->value = v;
	node->next = s->first;
	s->first= node;
}

//尾插
void weicha(SList* s, int v)
{
	Node* node = (Node*)malloc(sizeof(Node));  //创结点
	node->value = v;
	node->next = NULL;

	//找最后一个结点，需要一个结点保存头指针  然后保证头指针
	Node* cur = s->first;
	while (s->first != NULL)
		cur = cur->next;
	cur->next = node;  //插入node 结点
}
	
//中间插入
void weicha(SList* s, int v, int i)
{
	Node* node = (Node*)malloc(sizeof(Node));  //创结点

}




//链表逆置
//头查
void nizhi(SList* s)
{
	Node* cur =head;
	Node* pre = NULL;

	while (cur != NULL)
	{
		Node* next = cue->next;
		node->value = v;
		node->next = s->first;
		s->first = node;
	}
}