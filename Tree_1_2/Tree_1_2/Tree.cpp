#define _CRT_SECURE_NO_WARNINGS  1
#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>


typedef char BTdatatype;

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	BTdatatype data;

}BT;

void PreOrder(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	PreOrder(root->left);
	printf("%c ", root->data);
	PreOrder(root->right);
}

void PostOrder(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%c ", root->data);
}

//������
void TreeSize(BT* root, int* i)
{
	if (root == NULL)
		return;
	else
		++(*i);
	TreeSize(root->left,i);
	TreeSize(root->right,i);
}


//�ݹ鷨
int TreeSize(BT* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}


//ʹ�ò㼶��������ԭ����öӣ��Ƚ��ȳ������ȸ��ڵ�Ž��ӣ��ڿ��Ƿ������ҽڵ�
//��һ���������ӽڵ�������Դ�����
void levelOrder(BT* root)
{
	Queue q;
	QueueInit(&q);
	if(root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BT* front = QueueFront(&q);
		printf("%c ", front->data);
		QueuePop(&q);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);

	}
	printf("\n");
	QueueDestroy(&q);
}

//��һ��Ҷ�ӽڵ�ķ���
int Treeleafsize(BT* root)
{
	if (root == NULL)
		return 0;

	if (root->left== NULL && root->right == NULL)
		return 1;
	return Treeleafsize(root->left) + Treeleafsize(root->right);
}
int main()
{
	//int a;
	BT* A = (BT*)malloc(sizeof(BT));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BT* B = (BT*)malloc(sizeof(BT));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BT* C = (BT*)malloc(sizeof(BT));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BT* D = (BT*)malloc(sizeof(BT));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BT* E = (BT*)malloc(sizeof(BT));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PreOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	//int size = 0,z;
	//TreeSize(A,&size);
	//printf("���Ľڵ���:%d", size);
	printf("%d", TreeSize(B));
	levelOrder(A);
	return 0;
}