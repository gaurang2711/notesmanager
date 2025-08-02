#include<stdio.h>

void disp(int *arr){
    for(int i = 0; i < 4; i++){
        printf("[%d]\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {35, 66, 10, 31};
    printf("Before Sort: \n");
    disp(arr);

    for(int i = 0; i < 4 - 1; i++){
        for(int j = 0; j < 4 - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nAfter Sort: \n");
    disp(arr);

        printf("\n--CODED BY GAURANG DALAL--\n");

    return 0;
}