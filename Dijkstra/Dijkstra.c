#include<stdio.h>
#define INFINITY 999

void dij(int cost[10][10], int n, int source, int v[10], int d[10])
{
   int least, i, j, u;

   for(i=1; i<=n; i++)
	{
		least = INFINITY;
		for(j=1; j<=n; j++)
		{
			if(v[j] == 0 && d[j] < least)
			{
				least = d[j];
				u = j;
			}
		}

        v[u] = 1;

        for(j=1; j<=n; j++)
        {
            if(v[j]==0 && (d[j] > (d[u] + cost[u][j])))
            d[j] = d[u] + cost[u][j];
        }

	}

}

int main(){

    int n;
    int cost[10][10];
    int source;
    int v[10];
    int d[10];
    int i, j;

    printf("\nENTER NUMBER OF NODE: ");
    scanf("%d", &n);

    printf("\nENTER SOURCE: ");
    scanf("%d", &source);

    printf("\nENTER COST ADJ MATRIX: \n\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &cost[i][j]);

    for(i=1; i<=n; i++)
    {
        d[i] = cost[source][i];
        v[i] = 0;
    }

    dij(cost, n, source, v, d);

    for(i=1; i<=n; i++)
        printf("\n\t\t\t%d ---> %d = %d", source, i, d[i]);

    printf("\n\n");
    return 0;

}
