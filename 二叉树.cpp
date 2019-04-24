#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stack> 
#include<queue>
#include<iostream>
using namespace std;
/*
1. 熟悉树的概念以及相关概念
2. 了解树的存储方式以及其区别
3. 了解树的应用场景
4. 熟悉二叉树的基本概念以及性质
5. 熟悉满二叉树和完全二叉数，并掌握其区别
6. 熟悉二叉树的静态存储与链式存储
7. 实现链式数据结构的以下基本操作：
*/
typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* pLeft;
	struct BTNode* pRight;
	BTDataType data;
}BTNode;



// 1. 创建二叉树 
BTNode* CreateBinTree(BTNode* array, int size)
{
	BTDataType data;
	scanf("%d", &data);

	if (data == 0)     //如果到了叶子节点，接下来的左、右子树分别赋值为0
	{
		array = NULL;
	}
	else
	{

		array = (BTNode*)malloc(sizeof(BTNode));
		array->data = data;
		size++;
	    CreateBinTree(array->pLeft,size);  //递归创建左子树
		CreateBinTree(array->pRight,size);  //递归创建右子树

	}

	return array;
}



// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;

	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	Node->data = pRoot->data;
	Node->pLeft=CopyBinTree(pRoot->pLeft);
	Node->pRight=CopyBinTree(pRoot->pRight);

	return Node;
}
// 销毁二叉树 
//判断是否左节点，如果存在左节点一直递归下去；
//判断是否右节点，如果存在右节点一直递归下去；
//当一个结点无左结点和右结点，将结点free掉。
void DestroyBinTree(BTNode** pRoot)
{
	if (*pRoot==NULL)
	{
		return;
	}

	if ((*pRoot)->pLeft!=NULL)
	{
		DestroyBinTree((*pRoot)->pLeft);
	}

	if ((*pRoot)->pRight != NULL)
	{
		DestroyBinTree((*pRoot)->pRight);
	}

	free(pRoot);
	*pRoot = NULL;
}

// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot)   //前序
{
	if (pRoot == NULL)
		return;

	printf("%d", pRoot->data);
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

//先序遍历：
//①首先访问根节点是否为空，则入栈→输出栈顶元素→当前节点的左子树入栈     
//②当左子树为空，则栈顶元素出栈，转向该节点的右子树                  
//③全部元素出栈以后，结束循环
void PreOrderNor(BTNode* pRoot, vector<int> &path)
{
	//非递归前序遍历

	    stack<BTNode *> s;
		BTNode *p = pRoot;

		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				path.push_back(p->data);
				s.push(p);
				p = p->pLeft;
			}

			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->pRight;
			}
		}
	
}



void InOrder(BTNode* pRoot)  //中序
{
	if (pRoot == NULL)
		return;

	PreOrder(pRoot->pLeft);
	printf("%d", pRoot->data);
	PreOrder(pRoot->pRight);
}

//中序遍历：
//①入栈→当前节点的左子树入栈
//②当左子树为空，则栈顶元素出栈，输出栈顶元素→转向该节点的右子树
//③栈为空时，结束循环
void InOrderNor(BTNode* pRoot, vector<int> &path)
{
	//非递归中序遍历
		stack<BTNode *> s; 
		BTNode *p = pRoot; 
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{ 
				s.push(p); 
				p = p->pLeft;
			}        
			if (!s.empty())
			{ 
				p = s.top(); 
				path.push_back(p->data);
				s.pop(); 
				p = p->pRight;
			}
		}
}

void PostOrder(BTNode* pRoot)  //后序
{
	if (pRoot == NULL)
		return;

	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
	printf("%d", pRoot->data);
}

void PostOrderNor(BTNode* pRoot, vector<int> &path)
{
	//非递归后序遍历-迭代
		stack<BTNode *> s; 
		BTNode *p = pRoot;  
		BTNode *temp;  
		while (p != NULL || !s.empty()) 
		{
			while (p != NULL) //沿左子树一直往下搜索，直至出现没有左子树的结点  
			{
				BTNode *tempNode = new BTNode;         
				tempNode->btnode = p;
				tempNode->isFirst = true; 
				s.push(tempNode); 
				p = p->pLeft;
			}        
			if (!s.empty())
			{
				temp = s.top();
				s.pop();
				if (temp->isFirst == true)   //表示是第一次出现在栈顶     
				{
					temp->isFirst = false; 
					s.push(temp); 
					p = temp->btnode->right;
				}     
				else  //第二次出现在栈顶     
				{
					path.push_back(temp->btnode->val);    
					p = NULL; 
				} 
			}
		}
}


//队列实现：
//1、首先将二叉树的根节点push到队列中，判断队列不为NULL，就输出队头的元素，
//2、判断节点如果有孩子，就将孩子push到队列中，
//3、遍历过的节点出队列，
//4、循环以上操作，直到Tree == NULL

void LevelOrder1(BTNode &Tree) //层序遍历_队列实现
{
	queue < BTNode> q;
	if (Tree != NULL)
	{
		q.push(Tree);   //根节点进队列
	}

	while (q.empty() == false)  //队列不为空判断
	{
		cout << q.front()->data << " → ";

		if (q.front()->pLeft != NULL)   //如果有左孩子，左孩子入队列
		{
			q.push(q.front()->pLeft);
		}

		if (q.front()->pRight != NULL)   //如果有右孩子，右孩子入队列
		{
			q.push(q.front()->pRight);
		}
		q.pop();  //已经遍历过的节点出队列
	}
}


//数组实现：
//实现过程
//1、创建一个指针数组，保存二叉树结构体指针，
//2、保存二叉树根节点，再申请变量 in、out ，控制数组，在遍历过程中，始终能找到节点和该节点的前一个节点，
//3、循环以上过程
void LevelOrder2(BTNode Tree)  //层序遍历
{
	BTNode temp[100];   //创建指针数组
	int in = 0;
	int out = 0;

	temp[in++] = Tree;  //先保存二叉树根节点 

	while (in > out)
	{
		if (temp[out])
		{
			cout << temp[out]->data << " → ";
			temp[in++] = temp[out]->leftPtr;
			temp[in++] = temp[out]->rightPtr;
		}
		out++;
	}
}


// 二叉树结点中所有的 value 都不重复
// 找结点的 value 是 v 的结点
// 如果找到了，返回 v 所在的结点地址
// 如果没找到，返回 NULL
// Find 返回 NULL 意味着没找到，返回 非 NULL，意味着找到了
// 先确定根结点 -> 左子树中是否包含 -> 右子树中是否包含
// 如果根结点就是，不需要再去左右子树查找了
// 如果左子树找到了，不需要去右子树找了
BTNode * Find(BTNode *pRoot, int v) {
	if (pRoot == NULL) {
		return NULL;
	}

	// 先去根找
	if (pRoot->data == v) {
		// 找到了
		return pRoot;
	}
	// 如果根没找到，去左子树找
	BTNode *result = Find(pRoot->pLeft, v);
	if (result != NULL) {
		// 左子树里找到了
		return result;
	}

	// 如果左子树没找到，去右子树找
	result = Find(pRoot->pRight, v);
	if (result != NULL) {
		return result;
	}
	else {
		return NULL;
	}
}



// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot) //遍历方式
{
	if (pRoot == NULL)
		return;

	int size;
	size++;

	GetNodeCount(pRoot->pLeft);
	GetNodeCount(pRoot->pRight);

	return size;
}


int GetNodeCount2(BTNode *pRoot)   // 递推的方式
{
	if (pRoot == NULL) 
	{
		return 0;
	}

	int left = GetNodeCount2(pRoot->pLeft);
	int right = GetNodeCount2(pRoot->pRight);

	return left + right + 1;
}

// 求二叉树的高度 
int Height(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;

	int left = Height(pRoot->pLeft);
	int right = Height(pRoot->pRight);

	return (left < right ? right: left)+1;
}

// 检测二叉树是否平衡O(N^2) 
int IsBalanceTree(BTNode* pRoot)
{

}

// 检测二叉树是否平衡O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height)
{

}

//检测二叉树是否平衡
bool IsBalanceTree(BTNode* pRoot, int & depth)
{
	//如果为空，往父节点返
	if (pRoot == NULL)
	{
		depth = 0;
		return true;
	}
	//记录左节点和右节点深度
	int left = 0;
	int right = 0;
	//采取传引用的方式，下层递归进行对深度修改以后会影响上一层
	if (IsBalanceTree(pRoot->pLeft, left) && IsBalanceTree(pRoot->pRight, right))
	{
		//计算平衡因子
		int pf = right - left;
		//判断平衡因子是否合法
		if (pfIsInvaild(pf))
		{
			//合法就让自身加上子树的深度，然后因为是传引用，所以当递归回到上一层的时候，上层中的right和left就是左右子树的深度
			depth = 1 + (right > left ? right : left);
			return true;
		}
	}
	return false;
}

//判断平衡因子是否合法
bool pfIsInvaild(const int& pf)
{
	return abs(pf) < 2;
}


// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL) 
	{
		return 0;
	}

	if (pRoot->pLeft == NULL&&pRoot->pRight == NULL)
		return 1;

	int left=GetLeafNodeCount(pRoot->pLeft);
	int right=GetLeafNodeCount(pRoot->pRight);

	return left + right + 1;
}

// 获取二叉树第K层节点的个数 
//步骤
//如果空树 为0
//如果不为空 第一层为1
//求第K层 可以先求一左树的k - 1层 + 右树的k - 1层
//直到每次执行到一个根的 第一层返回1， 如果没有的话返回0
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	
	if (pRoot == NULL) 
	{
		return 0;
	}

	if (K == 1)
	{	// 隐含的前提是, root != NULL
		return 1;
	}

	return GetKLevelNodeCount(pRoot->pLeft, K - 1)
		+ GetKLevelNodeCount(pRoot->pRight, K - 1);
	

}


// 求二叉树的镜像 
bool Mirror(BTNode* pRoot1,BTNode* pRoot2)
{
	if (pRoot1==NULL&&pRoot2==NULL)
	{
		return 1;
	}

	if (pRoot1==NULL||pRoot2==NULL)
	{
		return 0;
	}

	return pRoot1->data == pRoot2->data
		&& Mirror(pRoot1->pLeft, pRoot2->pRight)
		&& Mirror(pRoot1->pRight, pRoot2->pLeft);
}

//判断是不是子树
bool isSameTree(struct BTNode *p, struct BTNode *q) {
	if (p == NULL && q == NULL) {
		return true;
	}

	if (p == NULL || q == NULL) {
		return false;
	}

	return p->data == q->data
		&& isSameTree(p->pLeft, q->pLeft)
		&& isSameTree(p->pRight, q->pRight);
}