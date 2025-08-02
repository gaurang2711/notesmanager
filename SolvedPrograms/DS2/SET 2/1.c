#include<stdio.h>

void disp(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

void merger(int *arr, int low, int mid, int high){
    int i, j, k;
    int copArr[100];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            copArr[k] = arr[i];
            i++;
        }
        else{
            copArr[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        copArr[k] =  arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        copArr[k] = arr[j];
        k++;
        j++;
    }

    for(int i = 0; i <= high; i++){
        arr[i] = copArr[i];
    }
}

void mergeSort(int *arr, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merger(arr, low, mid, high);
    }
}

int main(){
    int n = 5;
    int arr[n];
    printf("Enter 5 elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("--Before Sort--\n");
    disp(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("--After Sort--\n");
    disp(arr, n);

    printf("\n--CODED BY GAURANG DALAL--\n");
    return 0;
}