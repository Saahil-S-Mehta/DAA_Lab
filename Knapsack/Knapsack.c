#include <stdio.h>

int max(int x, int y){
    return x>y?x:y;
}
int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   printf("\n\nTABLE :\n");
   for(int i =0; i<=n; i++){
       for(int j =0; j<=n+1; j++){
            printf("%d\t", K[i][j]);
        }
        printf("\n");
   }

   return K[n][W];
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the value of each element : ");
    int val[n], wt[n], max_value;
    for(int i = 0; i<n; i++){
        scanf("%d", &val[i]);
    }
    printf("\nEnter the weight of each element : ");
    for(int i = 0; i<n; i++){
        scanf("%d", &wt[i]);
    }
    printf("\nEnter the maximum weight knapsack can carry : ");
    scanf("%d",&max_value);
    printf("\nValue = %d\n\n", knapsack(max_value, wt, val, n));
    return 0;
}
