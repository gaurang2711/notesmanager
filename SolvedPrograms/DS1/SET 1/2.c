#include<stdio.h>
#include<stdlib.h>
#define NL printf("\n");

void printOP(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]", arr[i]);
    }
    NL
}

void insertionSort(int *arr, int n){
    int i, j, key;
    for(int i = 1; i <= n - 1; i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] >= key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n;
    int *ptr;
    printf("Enter n: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    printOP(ptr, n);
    insertionSort(ptr, n);
    printOP(ptr, n);

    printf("\n//Coded by Gaurang Dalal; SY BCA\n");
    return 0;
}