#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

int partitioner(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void qckSort(int *arr, int low, int high){
    int partInd;
    if(low < high){
        partInd = partitioner(arr, low, high);
        qckSort(arr, low, partInd - 1);
        qckSort(arr, partInd + 1, high);
    }
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
    printf("Done...\n");

    printf("--Before Sort--\n");
    disp(arr, n);
    qckSort(arr, 0, n - 1);
    printf("--After Sort--\n");
    disp(arr, n);

    printf("\n--CODED BY GAURANG DALAL--\n");

    return 0;
}