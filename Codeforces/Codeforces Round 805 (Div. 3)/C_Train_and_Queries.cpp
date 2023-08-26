#include<cstdio>
#include<map>
#include<cstdlib>
using namespace std;

typedef struct Node
{
	int first;
	int last;
}NODE;

map<int, NODE*> road;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k, input, i = 0;
		scanf("%d %d", &n, &k);
		while (i < n)
		{
			scanf("%d", &input);
			if (road.count(input) == 0)
			{
				NODE* u = new NODE;
				road.insert(pair<int, NODE*>(input, u));
				u->first = i;
				u->last = i;
			}
			else
				road[input]->last = i;
			i++;
		}
		while (k--)
		{
			int start, stop;
			scanf("%d %d", &start, &stop);
			if (road.count(start) == 0 || road.count(stop) == 0 || road[start]->first > road[stop]->last)
				printf("NO\n");
			else
				printf("YES\n");
		}
		if(t)
			road.erase(road.begin(), road.end());
	}
	return 0;
}