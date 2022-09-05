#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int counter = 0;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int split(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while(1){
        while( pivot >= arr[i] && i <= right && ++counter) i++;
        while( pivot < arr[j] && ++counter) j--;
        if(i < j )
            swap(&arr[i], &arr[j]);
        else{
            swap(&arr[left], &arr[j]);
            return j;
        }
    }
}

void quick_sort(int* arr, int start, int end){
    int p;
    if(start < end){
        p = split(arr, start, end);
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

void time_analysis(){
    int c1, c2, c3;
    int a[258], d[256], r[256];
    printf("\n\nTime Analysis:\nSIZE\tASC\tDESC\tRAND\n\n");
    for(int i = 16; i <= 256; i = i *2){
        for(int j = 0; j < i; j++){
            a[j] = j;
            d[j] = i - j;
            r[j] = rand() % i;
        }

        counter = 0;
        quick_sort(a, 0, i-1);
        c1 = counter;

        counter = 0;
        quick_sort(d, 0, i-1);
        c2 = counter;

        counter = 0;
        quick_sort(r, 0, i-1);
        c3 = counter;

        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
}

void customCase_sort(){
    int n;
    printf("\n\nEnter the number of array elements: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));

    printf("\nEnter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    printf("\n\nInput Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");

    clock_t begin = clock();
    quick_sort(arr, 0, n-1);
    clock_t end = clock();

    printf("\nSorted Array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n\n");

    free(arr);
}

int main(){
    int n;
    clock_t start = clock();

    customCase_sort();
    time_analysis();
    clock_t end = clock();
    printf("\nTotal Execution Time: %.6f secs\n",(double)(end - start)/CLOCKS_PER_SEC);
    getch();
    exit(0);
}
