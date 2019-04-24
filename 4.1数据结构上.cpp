#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
	Node* root;
	int used;
}Result;    

void find(Node* root, int value)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->value == value)
	{
		return root;
	}
	

	Node* result = find(root->left, value);
	if (result == NULL)
	{
		return NULL;
	}
	else
	{
		return result;
	}

	Node* result = find(root->right, value);
	if (result == NULL)
	{
		return NULL;
	}
	else
	{
		return result;
	}

}


//前序构建二叉树
Result CreateTree(int preorder[], int size)
{
	if (size == 0)
	{
		Result r = { NULL, 0 };
		return r;
	}

	char rootvalue = preorder[0];
	if (rootvalue == '#')
	{
		Result r = { NULL, 1 };
		return r;
	}

	Node* root = (Node*)malloc(sizeof(Node));
	root->value = rootvalue;


	Result leftResult = CreateTree(preorder + 1, size - 1);
	root->left = leftResult.root;


	Result rightResult = CreateTree(preorder + 1 + leftResult.used, x
										size - 1 - leftResult.used);
	root->right = rightResult.root;

	Result r = { root , leftResult.used + rightResult.used +1};
	return r;
}

//层序遍历（广度）
