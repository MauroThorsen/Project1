//#include <stdio.h>
//#include <stdlib.h>
//typedef struct NODE
//{
//	struct NODE* pre;
//	struct NODE* next;
//	int code;
//} node, *linklist;
//linklist creat(int x)
//{
//	int a = x - 1, b = 1;
//
//	linklist h;
//	node *p = NULL, *t;
//	h = (node*)malloc(sizeof(node*));
//	h->code = b++;
//	h->pre = NULL;
//	t = h;
//	while (a--)
//	{
//		p = (node*)malloc(sizeof(node));
//		t->next = p;
//		p->code = b++;
//		p->pre = t;
//		p->next = NULL;
//		t = p;
//	}
//	h->pre = p;
//	p->next = h;
//	return h;
//}
//int run(linklist i, int a, int b)
//{
//	int t, m[100], y[100], z, x, flag = 0;
//	node *p, *q, *h;
//	for (t = 0; t < b; t++)
//		scanf_s("%d", &m[t]);
//	for (t = 1; t <= a; t++)
//	{
//		h = creat(a);
//		flag = 0;
//		for (z = 0; z < a; z++)
//		{
//			for (x = 1; x <= t; x++)
//				h = h->next;
//			y[z] = h->code;
//			p = h->pre;
//			q = h->next;
//			p->next = q;
//			q->pre = p;
//			h = h->next;
//		}
//		for (x = 0; x < b; x++)
//			y[x] = y[z - b + x];
//		for (x = 0; x < b; x++)
//			if (y[x] != m[x])
//			{
//				flag = 1;
//				break;
//			}
//		if (flag == 0)
//			return t + 1;
//	}
//	return 0;
//}
//main()
//{
//	linklist h;
//	int a, b;
//	scanf_s("%d %d", &a, &b);
//	h = creat(a);
//	printf("%d",run(h, a, b));
//	system("pause");
//}