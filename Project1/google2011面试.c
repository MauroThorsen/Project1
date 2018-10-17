////给定2个大小分别为n, m的整数集合，分别存放在两个数组中 int A[n], B[m]，输出两个集合的交集。
//#include<stdio.h>
//#include<math.h>
//#define N 10000
//#define M 10000
//int A[N], B[M];
//int initalization()
//{
//	char c = '\0';
//	int i;
//	for (i = 0; i < N&&c != 'p'; i++)
//	{
//		scanf_s("%d", &A[i]);
//		c = getchar();
//	}
//	return i;
//}
//char *zip(int a[],int b)
//{
//	char m[M];
//	for (int i = 0; i < M; i++)
//		m[i] = '0';
//	for (int i = 0; i < b; i++)
//		m[a[i]] = '1';
//	return m;
//}
//int Max(int a[],int b)
//{
//	int max = 0;
//	for (int i = 0; i < b; i++)
//		if (a[i] > max)
//			max = a[i];
//	return max;
//}
//void main()
//{
//	int a=0, max;
//	char *m;
//	a=initalization();
//	max = Max(A, a);
//	m = zip(A,a);
//	for (int i = max+1;i>=0; i--)
//		printf("%c", m[i]);
//	//整型压缩，在输入时直接压缩，不要二次浪费（待实现）
//	
//	printf("\n");
//	system("pause");
//}