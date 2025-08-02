#include<stdio.h>

void disp(int *arr, int n){
    for(int i  = 0; i < n; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

void dividerOP(){
    printf("\n__--__--__--__--__--__--__--__--__--__--__--__--__\n");
}
int partition(int *arr, int low, int high){
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

void quickSorter(int *arr, int low, int high){
    int partInd;
    

    if(low < high){
        partInd = partition(arr, low, high);
        quickSorter(arr, low, partInd - 1);
        quickSorter(arr, partInd + 1, high);
    }
}

int main(){
    int n = 5;
    int arr[5];
    printf("Enter 5 elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("--Before Sort--\n");
    disp(arr, n);
    dividerOP();
    quickSorter(arr, 0, n - 1);
    printf("--After Sort--\n");
    disp(arr, n);

    return 0;
}