#include<stdio.h>
typedef struct
{
	int y;
	int x;
}lattice1;
typedef struct 
{
	int x;
	int y;
	int change;
	lattice1 nextstep[8];//下一步下哪
	int nextstep_number;//下一步的可选步数
}step;
/*
 -- -- -- -- -- -- -- --
|  |  |1 |  |2 |  |  |  |       
 -- -- -- -- -- -- -- --
|  |3 |  |  |  |4 |  |  |        
 -- -- -- -- -- -- -- --
|  |  |  |h |  |  |  |  |          
 -- -- -- -- -- -- -- -- 
|  | 5|  |  |  |6 |  |  |                       
 -- -- -- -- -- -- -- --
|  |  | 7|  |8 |  |  |  |                     
 -- -- -- -- -- -- -- --
*/
int checkboard[8][8];//棋盘
step chack[64];//栈

int chack_in(int x)
{
	if (chack[x + 1].x == -1)
		chack[x].nextstep_number = site(x);//出栈后再次进栈无法判定位置
	if (chack[x].nextstep_number == 0)
		return -1;
	chack[x + 1].x = chack[x].nextstep[0].x;
	chack[x + 1].y = chack[x].nextstep[0].y;
	checkboard[chack[x + 1].x][chack[x + 1].y] = 1;
	return 0;
}
int site(int sit)//判定位置
{
	int a = 0;
	if ((chack[sit].x - 1) >= 0 && (chack[sit].y - 2) >= 0 && checkboard[chack[sit].x - 1][chack[sit].y - 2] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x - 1;
		chack[sit].nextstep[a].y = chack[sit].y - 2;
		a++;
	}
	if ((chack[sit].x + 1) < 8 && (chack[sit].y - 2) >= 0 && checkboard[chack[sit].x + 1][chack[sit].y - 2] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x + 1;
		chack[sit].nextstep[a].y = chack[sit].y - 2;
		a++;
	}
	if ((chack[sit].x - 2) >= 0 && (chack[sit].y - 1) >= 0 && checkboard[chack[sit].x - 2][chack[sit].y - 1] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x - 2;
		chack[sit].nextstep[a].y = chack[sit].y - 1;
		a++;
	}
	if ((chack[sit].x + 2) < 8 && (chack[sit].y - 1) >= 0 && checkboard[chack[sit].x + 2][chack[sit].y - 1] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x + 2;
		chack[sit].nextstep[a].y = chack[sit].y - 1;
		a++;
	}
	if ((chack[sit].x - 2) >= 0 && (chack[sit].y + 1) <= 0 && checkboard[chack[sit].x - 2][chack[sit].y + 1] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x - 2;
		chack[sit].nextstep[a].y = chack[sit].y + 1;
		a++;
	}
	if ((chack[sit].x + 2) < 8 && (chack[sit].y + 1) < 8 && checkboard[chack[sit].x + 2][chack[sit].y + 1] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x + 2;
		chack[sit].nextstep[a].y = chack[sit].y + 1;
		a++;
	}
	if ((chack[sit].x - 1) >= 0 && (chack[sit].y + 2) < 8 && checkboard[chack[sit].x - 1][chack[sit].y + 2] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x - 1;
		chack[sit].nextstep[a].y = chack[sit].y + 2;
		a++;
	}
	if ((chack[sit].x + 1) < 8 && (chack[sit].y + 2) < 8 && checkboard[chack[sit].x + 1][chack[sit].y + 2] != 1)
	{
		chack[sit].nextstep[a].x = chack[sit].x + 1;
		chack[sit].nextstep[a].y = chack[sit].y + 2;
		a++;
	}
	return a;
}
void initalization()//棋盘初始化
{
	for (int a = 0; a < 8; a++)
		for (int b = 0; b < 8; b++)
			checkboard[b][a] = 0;
	for (int a = 0; a < 64; a++)
	{
		chack[a].x = -1;
		chack[a].y = -1;
	}
}
void chack_out(int a)
{
	checkboard[chack[a].x][chack[a].y] = 0;
	for (int i = 0; i <= chack[a].nextstep_number - 1; i++)
	{
		chack[a].nextstep[i].x = chack[a].nextstep[i + 1].x;
		chack[a].nextstep[i].y = chack[a].nextstep[i + 1].y;
	}
	chack[a].nextstep_number--;
}
int core()
{
	int a = 0;
	scanf_s("(%d,%d)", &chack[0].x, &chack[0].y);
	checkboard[chack[0].x][chack[0].y] = 1;
	while (a < 64)
	{
		int i;
		i = chack_in(a);
		if (i == -1)
		{
			checkboard[chack[a].x][chack[a].y] = 0;
			chack_out(--a);
			if (a == 0)
				break;
		}
		if (i == 0)
			a++;
	}//不知原因的没有结果
	if (a == 63)
		return 1;
	else return 0;
}
main()
{
	
	int x = 1;
		initalization();
		if (core() == 1)
			for (int i = 0; i < 65; i++)
			{
				printf(" (%d,%d) ", chack[i].x, chack[i].y);
				if (i % 7 == 0)
					printf("\n");
			}
		
	system("pause");
}

