//#include<stdio.h>
//typedef struct
//{
//	int flag;
//	int y;
//	int x;
//}lattice;
//typedef struct 
//{
//	int x;
//	int y;
//	int change;
//	lattice nextstep[8];
//	int step;
//	int nextstep_number;
//}step;
///*
// -- -- -- -- -- -- -- --
//|  |  |1 |  |2 |  |  |  |       
// -- -- -- -- -- -- -- --
//|  |3 |  |  |  |4 |  |  |        
// -- -- -- -- -- -- -- --
//|  |  |  |h |  |  |  |  |          
// -- -- -- -- -- -- -- -- 
//|  | 5|  |  |  |6 |  |  |                       
// -- -- -- -- -- -- -- --
//|  |  | 7|  |8 |  |  |  |                     
// -- -- -- -- -- -- -- --
//*/
//lattice checkboard[8][8];//棋盘
//step chack[65];//栈
//int site(int sit)//判定位置
//{
//	int site = 0;
//	int xx;
//	int yy;
//	xx = chack[sit].x;
//	yy = chack[sit].y;
//	chack[sit].nextstep_number = 0;
//	if (xx - 1 >= 1 && yy + 2 <= 8 && checkboard[xx - 2][yy + 1].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[0].x = xx-2;
//		chack[sit].nextstep[0].y = yy + 1;
//	}
//	if (xx + 1 <= 8 && yy + 2 <= 8 && checkboard[xx][yy + 1].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[1].x = xx;
//		chack[sit].nextstep[1].y = yy + 1;
//	}
//	if (xx - 2 >= 0 && yy + 1 <= 8 && checkboard[xx - 3][yy].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[2].x = xx-3;
//		chack[sit].nextstep[2].y = yy ;
//	}
//	if (xx + 2 <= 8 && yy + 1 <= 8 && checkboard[xx + 1][yy].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[3].x = xx+1;
//		chack[sit].nextstep[3].y = yy ;
//	}
//	if (xx - 2 >= 8 && yy - 1 >= 0 && checkboard[xx - 3][yy - 2].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[4].x = xx-3;
//		chack[sit].nextstep[4].y = yy -2;
//	}
//	if (xx + 2 <= 8 && yy - 1>=0 && checkboard[xx + 1][yy - 2].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[5].x = xx+1;
//		chack[sit].nextstep[5].y = yy -2;
//	}
//	if (xx - 1 >= 0 && yy - 2 >= 0 && checkboard[xx - 2][yy - 3].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[6].x = xx-2;
//		chack[sit].nextstep[6].y = yy -3;
//	}
//	if (xx + 1 <= 8 && yy - 2 >= 0 && checkboard[xx][yy - 3].flag == 0)
//	{
//		site++;
//		chack[sit].nextstep_number++;
//		chack[sit].nextstep[7].x = xx;
//		chack[sit].nextstep[7].y = yy -3;
//	}
//
//	return site;
//}
//void initalization()//棋盘初始化
//{
//	for (int a = 0; a < 8; a++)
//		for (int b = 0; b < 8; b++)
//		{
//			checkboard[a][b].y = b + 1;
//			checkboard[a][b].x = a + 1;
//		}
//}
//void core()
//{
//	int a = 0, t, m = 0;
//	chack[a].x = 1; chack[a].y = 1; chack[a].step = m++;
//	checkboard[chack[a].x - 1][chack[a].y - 1].flag = 1;
//	while (chack[64].step != 64)
//	{
//
//		t = site(a);//change:退步后改变步数
//		chack[a].change = 0;
//		if (t > 0)
//		{
//			chack[a+1].x = chack[a].nextstep[chack[a].change].x; chack[a+1].y = chack[chack[a].change].nextstep[0].y;
//			chack[a + 1].step = m++;a++;
//			checkboard[chack[a].x - 1][chack[a].y - 1].flag = 1;
//			
//		}
//		if (t == 0)
//		{
//			checkboard[chack[a].x - 1][chack[a].y - 1].flag = 0;
//			a = a - 2;
//			chack[a].change++;
//			m--;
//		}
//	}
//
//}
//main()
//{
//	initalization();
//	int x;
//	core();
//	for (int i = 0; i < 65; i++)
//		printf(" (%d,%d) \n", chack[i].x, chack[i].y);
//	system("pause");
//}
//
//
