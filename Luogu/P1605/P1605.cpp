#include<bits/stdc++.h>
using namespace std;
void route(int* p, int x, int y);
int maze[7][7] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int stx, sty, tarx, tary;
int main()
{
	int N, M, T;
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			maze[i][j] = 1;
	scanf("%d%d%d%d", &stx, &sty, &tarx, &tary);
	int Tx, Ty;
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &Tx, &Ty);
		maze[Tx][Ty] = 0;
	}
	int ans = 0;
	int* p = &ans;
	route(p, stx, sty);
	printf("%d\n", ans);
	return 0;
}
void route(int* p, int x, int y)
{
	if (x == tarx && y == tary)
	{
		(*p)++;
		return;
	}
	else if (maze[x - 1][y] == 0 && maze[x + 1][y] == 0 && maze[x][y - 1] == 0 && maze[x][y + 1] == 0)
		return;
	else
		for (int i = 0; i < 4; i++)
			if (maze[x + dx[i]][y + dy[i]] == 1)
			{
				maze[x][y] = 0;
				route(p, x + dx[i], y + dy[i]);
				maze[x][y] = 1;
			}
	//最后一个else后面的错误解法。此解法不能保证上下左右都试一遍，只能走上/下/左/右其中的一个。
/*else if (*(*(maze + x - 1) + y) == 1)
	{
		*(*(maze + x) + y) = 0;
		route(p, x - 1, y, Tarx, Tary);
		*(*(maze + x) + y) = 1;
	}
	else if (*(*(maze + x + 1) + y) == 1)
	{
		*(*(maze + x) + y) = 0;
		route(p, x + 1, y, Tarx, Tary);
		*(*(maze + x) + y) = 1;
	}
	else if (*(*(maze + x) + y - 1) == 1)
	{
		*(*(maze + x) + y) = 0;
		route(p, x, y - 1, Tarx, Tary);
		*(*(maze + x) + y) = 1;
	}
	else if (*(*(maze + x) + y + 1) == 1)
	{
		*(*(maze + x) + y) = 0;
		route(p, x, y + 1, Tarx, Tary);
		*(*(maze + x) + y) = 1;
	}*/
}
