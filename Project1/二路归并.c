#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Depth;
typedef struct data
{
	int a;
	struct data* next;
}data;
typedef struct full_binary_tree
{
	data* Data;
	int depth;
	struct full_binary_tree *left, *right, *father;
}full_binary_tree;
data *creat_data(int i)
{
	data *p, *q, *h;
	int n;
	n = pow(2, Depth - i);
	h = p = malloc(sizeof(data));
	h->a = 10000;
	for (int m = 0; m < n; m++)
	{
		q = malloc(sizeof(data));
		p->next = q;
		p = p->next;
	}
	p->next = h;
	return h;
}
//满二叉树的定义（以三叉链实现）
full_binary_tree *creat(int i, full_binary_tree *B)
{
	full_binary_tree *A;
	A = malloc(sizeof(full_binary_tree));
	A->depth = i;
	A->Data = creat_data(i);		
	if (i == 1)
		A->father = NULL;
	else A->father = B;
	if (A->depth == Depth)
	{
		A->left = A->right = NULL;
		return A;
	}
	A->left = A->right = creat(i + 1,A);
	return A;
}

main()
{
	full_binary_tree *A;
	int x;
	printf("待排序数的个数：");
	scanf_s("%d", &x);
	Depth = (int)(log(x) / log(2) + 1);
	A= malloc(sizeof(full_binary_tree));
	A = creat(1, A);
	
	/*sort(A);*/
    system("pause");
}













