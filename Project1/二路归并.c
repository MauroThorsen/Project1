//#include <stdio.h>
//main()
//{
//	int a[1000];
//	int x = 0;
//	int aaa;
//	while (scanf_s("%d", &a[x++]))
//	{ }
//	x--;
//	/*for (int i = 0; i < x; i++)
//		printf("%d\t", a[i]);*/
//    //¼ì²âº¯Êý
//	if (x % 2 != 0)
//	{
//		aaa = a[x];
//		x--;
//	}
//
//	system("pause");
//}













//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct {
//	int d;
//	int pw;
//	struct node *n;
//	struct node *f;
//}Int, *link;
//link creat(int n)
//{
//	link L;
//	L = (link)malloc(sizeof(Int));
//	int i;
//	Int *r, *p;
//	L->n = NULL;
//	L->d = 1;
//	scanf("%d", &L->pw);
//	r = L;
//	for (i = 2; i <= n; i++)
//	{
//		p = (link)malloc(sizeof(Int));
//		p->d = i;
//		scanf("%d", &p->pw);
//		p->n = NULL;
//		p->f= r;
//		r->n = p;
//		r = p;
//	}
//	p->n = L;
//	L->f = p;
//	return L;
//}
//int delate(link L, int n, int m)
//{
//	Int *p, *q, *t;
//	int i, k;
//	if (n == 0)
//		return 0;
//	p = t = L;
//	if (m < 0)
//		m = n;
//	for (i = 1; i <= m; i++)
//	{
//		q = p->f;
//		t = q->n;
//		p = p->n;
//	}
//	q->n = p;
//	p->f = q;
//	k = t->pw;
//	printf("%d ", t->d);
//	free(t);
//	n--;
//	if (n == 0)
//		return 0;
//	L = p;
//	delate(L, n, k);
//}
//void fun()
//{
//	int n, m;
//	link L;
//	scanf("%d", &n);
//	scanf("%d", &m);
//	L = creat(n);
//	delate(L, n, m);
//}
//int main()
//{
//	fun();
//}




