#include<stdio.h>

void disp(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

void merger(int *arr, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int copArr[5];
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
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
        copArr[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high){
        copArr[k] = arr[j];
        j++;
        k++;
    }

    for(int f = low; f <= high; f++){
        arr[f] = copArr[f];
    }
}

void mergeSort(int *arr, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merger(arr, low, mid, high);
    }
}

int main(){
    int n = 5;
    int arr[] = {20, 30, 44, 51, 87};
    printf("--Before Sort--\n");
    disp(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("--After Sort--\n");
    disp(arr, n);

    printf("\n--CODED BY GAURANG DALAL--\n");
    return 0;
}