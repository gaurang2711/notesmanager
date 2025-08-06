#include<stdio.h>
#include<stdlib.h>

int binSearch(int *arr, int low, int high, int key){
    if(low > high){
        return -1;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] < key){
        return binSearch(arr, mid + 1, high, key);
    }
    else{
        return binSearch(arr, low, mid - 1, key);
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

    int res = binSearch(ptr, 0, n - 1, key);

    if(res != -1){
        printf("%d found at [%d] location\n", key, res);
    }
    else{
        printf("ERROR!! Either the array is not sorted or there's something else\n");
    }

    return 0;
}