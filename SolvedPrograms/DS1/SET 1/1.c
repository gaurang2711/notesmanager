#include<stdio.h>
#include<stdlib.h>
#define NL printf("\n");

void printOP(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]", arr[i]);
    }
    NL
}

void bubbleSorter(int *arr, int n){
    int temp;
    for(int i = 0; i <= n - 1; i++){
        for(int j = 0; j < n - 1 -i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSorter(ptr, n);
    printOP(ptr, n);


    printf("\n--CODED BY GAURANG DALAL--\n");
    return 0;

}