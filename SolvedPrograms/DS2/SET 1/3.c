#include<stdio.h>
#include<stdlib.h>

void disp(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

int parti(int *arr, int low, int high){
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

void quickSort(int *arr, int low, int high){
    int partInd;
    if(low < high){
        partInd = parti(arr, low, high);
        quickSort(arr, low, partInd - 1);
        quickSort(arr, partInd + 1, high);
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
    printf("--Before Sort--\n");
    disp(ptr, n);
    quickSort(ptr, 0, n - 1);
    printf("--After Sort--\n");
    disp(ptr, n);

    printf("\n--CODED BY GAURANG DALAL--\n");

    return 0;
}