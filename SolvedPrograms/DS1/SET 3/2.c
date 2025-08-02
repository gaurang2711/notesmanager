#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

void insertSort(int *arr, int n){
    int i, j, key;
    for(i = 1; i <= n - 1; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    srand(time(NULL));
    int arr[n];
    printf("Enter %d elements: ");
    for(int i = 0; i < n; i++){
        arr[i] = rand(); 
    }
    printf("Before Sort: \n");
    disp(arr, n);
    printf("\n----------------------------------------------------------------------------------------\n");
    insertSort(arr, n);
    printf("After Sort: \n");
    disp(arr, n);

        printf("\n--CODED BY GAURANG DALAL--\n");
}