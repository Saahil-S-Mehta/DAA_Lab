#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256
int table[SIZE];

void shift( char p[25])
{
    int i,m;
    m=strlen(p);
    for(i=0;i<SIZE;i++)
    {
        table[i]=m;
    }
    for(i=0;i<=m-2;i++)
    {
        table[p[i]]=m-i-1;
    }
}

int horsepool(char T[100],char p[25])
{
    int m,n,k,i;
    shift(p);
    m=strlen(p);
    n=strlen(T);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<m&&(p[m-1-k]==T[i-k]))
        {
            k=k+1;
        }
        if(k==m)
        {
            return i-m+1;
        }
        else
        {
            i=i+table[T[i]];
        }
    }
    return -1;
}

int main()
{
    char text[100],pattern[25];
    int res;
    printf("\nRead Text :\t");
    scanf("%[^\n]s",text);
    printf("\nRead Patern :\t");
    scanf("%s",pattern);
    res=horsepool(text,pattern);
    if(res==-1)
    {
        printf("\n\nPattern not found\n");
    }
    else
    {
        printf("\n\nPattern found at %d\n",res);
    }
}

