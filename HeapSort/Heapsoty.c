#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int count=0;

void heapify(int a[MAX], int n){
    int i, j, k, v, flag;
    for(i=n/2;i>=1;i--){
    k=i;
    v=a[k];
    flag=0;
        while(!flag && 2*k<=n){
            j=2*k;
            if(j<n){
                count++;
                if(a[j]<a[j+1])
                    j=j+1;
            }
            if(v>=a[j])
                flag=1;
            else{
                a[k]=a[j];
                k=j ;
            }
        }
        a[k]=v;
    }
}

void heapsort(int a[MAX], int n){
    int i, temp;
    for(i=n;i>1;i--){
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}

int main()
{
    int i, j, n;
    int a[MAX], b[MAX], c[MAX];
    int c1, c2, c3;
    printf("\nHEAP SORT\n");
    printf("\nEnter the value of n- ");
    scanf("%d",&n);
    printf("\nEnter the array elements- ");

    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    heapify(a,n);
    heapsort(a,n);
    printf("\nSorted elements are- ");

    for(i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n\nThe number of comparisons made - %d", count);
    printf("\n\nTIME COMPLEXITY ANALYSIS - heapsort is in bottom-up approach");
    printf("\n\nSIZE\tASC\tDESC\tRAND\n");

    for(i=16;i<550;i=i*2){
        for(j=1;j<=i;j++){
            a[j]=j;
                b[j]=i-j;
            c[j]=rand()%i;
        }
        count = 0;
        heapify(a,i);
        heapsort(a,i);
        c1 = count;
        count = 0;
        heapify(b,i);
        heapsort(b,i);
        c2 = count;
        count = 0;
        heapify(c,i);
        heapsort(c,i);
        c3 = count;
        printf("\n %d\t %d\t %d\t %d",i, c1, c2, c3);
    }

printf("\n");
return(0);
}
