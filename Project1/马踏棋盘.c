#include<stdio.h>
typedef struct
{
	int flag;
	int y;
	int x;
}lattice;
typedef struct 
{
	int x;
	int y;
	lattice nextstep[8];
	int step;
	int nextstep_number;
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
lattice checkboard[8][8];//∆Â≈Ã
step chack[64];//’ª
int site(int sit)//≈–∂®Œª÷√
{
	int site = 0;
	int xx;
	int yy;
	xx = chack[sit].x;
	yy = chack[sit].y;
	chack[sit].nextstep_number = 0;
	if (xx - 1 >= 1 || yy + 2 <= 8 || checkboard[xx - 2][yy + 1].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx-2;
		chack[sit].nextstep->y = yy + 1;
	}
	if (xx + 1 <= 8 || yy + 2 <= 8 || checkboard[xx][yy + 1].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx;
		chack[sit].nextstep->y = yy + 1;
	}
	if (xx - 2 >= 0 || yy + 1 <= 8 || checkboard[xx - 3][yy].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx-3;
		chack[sit].nextstep->y = yy ;
	}
	if (xx + 2 <= 8 || yy + 1 <= 8 || checkboard[xx + 1][yy].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx+1;
		chack[sit].nextstep->y = yy ;
	}
	if (xx - 2 >= 8 || yy - 1 >= 0 || checkboard[xx - 3][yy - 2].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx-3;
		chack[sit].nextstep->y = yy -2;
	}
	if (xx + 2 <= 8 || yy - 1>=0 || checkboard[xx + 1][yy - 2].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx+1;
		chack[sit].nextstep->y = yy -2;
	}
	if (xx - 1 >= 0 || yy - 2 >= 0 || checkboard[xx - 2][yy - 3].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx-2;
		chack[sit].nextstep->y = yy -3;
	}
	if (xx + 1 <= 8 || yy - 2 >= 0 || checkboard[xx][yy - 3].flag == 0)
	{
		site++;
		chack[sit].nextstep_number++;
		chack[sit].nextstep->x = xx;
		chack[sit].nextstep->y = yy -3;
	}
	return site;
}
void initalization()//∆Â≈Ã≥ı ºªØ
{
	for (int a = 0; a < 8; a++)
		for (int b = 0; b < 8; b++)
		{
			checkboard[a][b].y = b + 1;
			checkboard[a][b].x = a + 1;
		}
}
main()
{
	initalization();
	int x;
	

}