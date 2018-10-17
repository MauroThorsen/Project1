#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Depth 8
//void merge(int a[], int b)
//{
//
//}
//void divide(int a[],int b)
//{
//	if (b != 2)
//		divide(a, b / 2);
//	merge(a, b);
//}
//为什么不直接定义二叉树，在二叉树中操作
 struct data
{
	int a;
	struct data* next;
};
 typedef struct data data;
typedef struct full_binary_tree
{
	data *Data;
	int depth;
	struct full_binary_tree *left, *right, *father;
}full_binary_tree;

full_binary_tree creat()
{
	data *p;
	int i = 1, n;
	while (i <= Depth)
	{
		n = pow(2, Depth - i);
		p = malloc(sizeof(data));
	}
}
main()
{
	full_binary_tree A;
    system("pause");
}













