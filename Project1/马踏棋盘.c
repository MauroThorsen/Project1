////#include<stdio.h>
////typedef struct
////{
////	int x;int y;
////}lattice1;
////typedef struct 
////{
////	int x;
////	int y;
////	int change;
////	lattice1 nextstep[8];//下一步下哪
////	int nextstep_number;//下一步的可选步数
////}step;
/////*
//// -- -- -- -- -- -- -- --
////|  |  |1 |  |2 |  |  |  |       
//// -- -- -- -- -- -- -- --
////|  |3 |  |  |  |4 |  |  |        
//// -- -- -- -- -- -- -- --
////|  |  |  |h |  |  |  |  |          
//// -- -- -- -- -- -- -- -- 
////|  | 5|  |  |  |6 |  |  |                       
//// -- -- -- -- -- -- -- --
////|  |  | 7|  |8 |  |  |  |                     
//// -- -- -- -- -- -- -- --
////*/
////int checkboard[8][8];//棋盘
////step chack[64];//栈
////int chack_in(int x)
////{
////	if (chack[x + 1].x == -1 || chack[x].change == 1)
////	{
////		chack[x].nextstep_number = site(x);
////		chack[x].change = 0;
////	}//出栈后再次进栈无法判定位置
////	if (chack[x].nextstep_number == 0)
////		return -1;
////	chack[x + 1].x = chack[x].nextstep[0].x;
////	chack[x + 1].y = chack[x].nextstep[0].y;
////	checkboard[chack[x + 1].x][chack[x + 1].y] = 1;
////	return 0;
////}
////int site(int sit)//判定位置
////{
////	int a = 0;
////	if ((chack[sit].x - 1) >= 0 && (chack[sit].y - 2) >= 0 && checkboard[chack[sit].x - 1][chack[sit].y - 2] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x - 1;
////		chack[sit].nextstep[a].y = chack[sit].y - 2;
////		a++;
////	}
////	if ((chack[sit].x + 1) < 8 && (chack[sit].y - 2) >= 0 && checkboard[chack[sit].x + 1][chack[sit].y - 2] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x + 1;
////		chack[sit].nextstep[a].y = chack[sit].y - 2;
////		a++;
////	}
////	if ((chack[sit].x - 2) >= 0 && (chack[sit].y - 1) >= 0 && checkboard[chack[sit].x - 2][chack[sit].y - 1] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x - 2;
////		chack[sit].nextstep[a].y = chack[sit].y - 1;
////		a++;
////	}
////	if ((chack[sit].x + 2) < 8 && (chack[sit].y - 1) >= 0 && checkboard[chack[sit].x + 2][chack[sit].y - 1] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x + 2;
////		chack[sit].nextstep[a].y = chack[sit].y - 1;
////		a++;
////	}
////	if ((chack[sit].x - 2) >= 0 && (chack[sit].y + 1) <= 0 && checkboard[chack[sit].x - 2][chack[sit].y + 1] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x - 2;
////		chack[sit].nextstep[a].y = chack[sit].y + 1;
////		a++;
////	}
////	if ((chack[sit].x + 2) < 8 && (chack[sit].y + 1) < 8 && checkboard[chack[sit].x + 2][chack[sit].y + 1] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x + 2;
////		chack[sit].nextstep[a].y = chack[sit].y + 1;
////		a++;
////	}
////	if ((chack[sit].x - 1) >= 0 && (chack[sit].y + 2) < 8 && checkboard[chack[sit].x - 1][chack[sit].y + 2] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x - 1;
////		chack[sit].nextstep[a].y = chack[sit].y + 2;
////		a++;
////	}
////	if ((chack[sit].x + 1) < 8 && (chack[sit].y + 2) < 8 && checkboard[chack[sit].x + 1][chack[sit].y + 2] != 1)
////	{
////		chack[sit].nextstep[a].x = chack[sit].x + 1;
////		chack[sit].nextstep[a].y = chack[sit].y + 2;
////		a++;
////	}
////	return a;
////}
////void initalization()//棋盘初始化
////{
////	for (int a = 0; a < 8; a++)
////		for (int b = 0; b < 8; b++)
////			checkboard[b][a] = 0;
////	for (int a = 0; a < 64; a++)
////	{
////		chack[a].x = -1;
////		chack[a].y = -1;
////		chack[a].change = 0;
////	}
////}
////void chack_out(int a)
////{
////	checkboard[chack[a].x][chack[a].y] = 0;
////	for (int i = 0; i <= chack[a].nextstep_number - 1; i++)
////	{
////		chack[a].nextstep[i].x = chack[a].nextstep[i + 1].x;
////		chack[a].nextstep[i].y = chack[a].nextstep[i + 1].y;
////	}
////	chack[a].nextstep_number--;
////}                        
////int core()
////{
////	int a = 0;
////	scanf_s("(%d,%d)", &chack[0].x, &chack[0].y);
////
////	checkboard[chack[0].x][chack[0].y] = 1;
////	while (a < 64)
////	{
////		int i;
////		i = chack_in(a);
////		if (i == -1)
////		{
////			checkboard[chack[a].x][chack[a].y] = 0;
////			chack[a].x = chack[a].y = -2;
////			chack[a].change = 1;
////			chack_out(--a);
////			if (a == 0)
////				break;
////		}
////		if (i == 0)
////			a++;
////	}
////	if (a == 63)
////		return 1;
////	else return 0;
////}
////main()
////{
////	int x = 1;
////	initalization();
////	if (core() == 1)
////		for (int i = 0; i < 65; i++)
////		{
////			printf(" (%d,%d) ", chack[i].x, chack[i].y);
////			if (i % 7 == 0)
////				printf("\n");
////		}
////		
////	system("pause");
////}
//# include<stdio.h>
//# define M 100
//typedef struct
//{
//	int a[M];
//	int front, rear;
//}sq;
//void init(sq *q)
//{
//	q->rear = q->front = 0;
//}
//int  enter(sq *q, int x)
//{
//	if ((q->rear + 1) % M == q->front)
//		return 0;
//	else
//	{
//		q->a[q->rear] = x;
//		q->rear = (q->rear + 1) % M;
//		return 1;
//	}
//}
//int delet(sq *q, int *x)
//{
//	if (q->front == q->rear)
//		return 0;
//	else
//	{
//		*x = q->a[q->front];
//		q->front = (q->front + 1) % M;
//		return 1;
//	}
//}
//int get(sq *q, int *x)
//{
//	if (q->front == q->rear)
//		return 0;
//	else
//	{
//		*x = q->a[q->front];
//		return 1;
//	}
//}
//void main()
//{
//	sq q;
//	int n, m, i, x, y;
//	init(&q);
//	printf("请输入杨辉三角的行数:");
//	scanf_s("%d", &m);
//	enter(&q, 1);
//	for (n = 2; n <= m; n++)
//	{
//		enter(&q, 1);
//		for (i = 1; i <= n - 2; i++)
//		{
//			delet(&q, &x);
//			printf("%d ", x);
//			get(&q, &y);
//			y = y + x;
//			enter(&q, y);
//		}
//		delet(&q, &x);
//		printf("%d", x);
//		printf("\n");
//		enter(&q, 1);
//	}
//	while (q.front != q.rear)
//	{
//		delet(&q, &x);
//		printf("%d ", x);
//	}
//	system("pause");
//}