#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printFunc(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

void buprintf("--Before Sort--\n");ort(int *arr, int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void divider(){
    printf("\n--------------------------------------------------------\n");
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));  
    printf("Automatically generating numbers....\n");
    for(int i = 0; i < n; i++){
        arr[i] = rand();  
    }

    printf("Before Sort\n");
    printFunc(arr, n);
    divider();
    printf("--Before Sort--\n");
    buprintf("--Before Sort--\n");ort(arr, n);
    divider();
    printf("After sort: \n");
    printFunc(arr, n);

    printf("\n--CODED BY GAURANG DALAL--\n");
    return 0;
}