//pos的后面插入
void houmian()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = v;
	node->next = pos->next;
	pos->next = node;
}


//链表           
//删除链表中所有的V 值

if (head == NULL)
{
	return;
}
Node* cur = p->First;
while (cur->next->value != NULL)
{
	if (cur->next->value == V)
	{
		struct ListNode* next = cur->next->next;
		free(cur->next);
		cur->next = next;
	}
	else
	{
		cur = cur->next;
	}
}
if (head->V == V)
{
	Node* newhead = head->next;
	freee(head);
	return newhead;
}

//反转链表**
//三个指针实现
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
//链表的中间点：利用快慢指针  双指针遍历 *


//找倒数第k个节点：两个节点 同一位置 一个前进k个  再两个同时走 远的的那个到NULL 近的就找到了



//合并两个有序链表**
1->2->3,2->3->4
合并：1->1->2->2->3->4


struct ListNode* hebing(sttuct ListNode* L1, sttuct ListNode* L2)  
{
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

};

//分成大与小于


//删除全部重复的节点



//回文