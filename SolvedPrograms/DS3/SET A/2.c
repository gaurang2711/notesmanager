#include <stdio.h>

void disp(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

int binSearch(int *arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n, key;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    printf("You array: ");
    disp(arr, n);
    int res = binSearch(arr, n, key);
    if(res != -1){
        printf("%d found at [%d] location\n", key, res);
    }
    else{
        printf("We are afraid that either the array you entered is not sorted or something else...");
    }

    return 0;
}