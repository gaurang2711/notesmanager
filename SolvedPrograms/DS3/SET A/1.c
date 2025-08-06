#include<stdio.h>
#include<stdlib.h>

void disp(int *arr, int n){
    printf("[");
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("]");
    printf("\n");
}

void linSer(int *arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            printf("%d Element found at [%d] location", key, i + 1);
        }
    }
}
int main(){
    int n;
    int *ptr;
    int key;
    printf("Enter n: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);
    printf("Your array: ");
    disp(ptr, n);
    linSer(ptr, n, key);

    return 0;

}