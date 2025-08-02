#include <stdio.h>

void disp(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\t", a[i]);
    }
    printf("\n");
}

int part(int *a, int l, int h)
{
    int piv = a[l];
    int i = l + 1;
    int j = h;
    do
    {
        while (a[i] <= piv)
        {
            i++;
        }
        while(a[j] > piv){
            j--;
        }
        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int *a, int l, int h)
{
    int pI;
    if (l < h)
    {
        pI = part(a, l, h);
        quickSort(a, l, pI - 1);
        quickSort(a, pI + 1, h);
    }
}

int main()
{
    int n = 5;
    int A[] = {17, 12, 23, 4, 8};
    printf("--Before Sort--\n");
    disp(A, n);
    printf("Sorting....\n");
    quickSort(A, 0, n - 1);
    printf("Sorting finished...\n");
    printf("--After Sort--\n");
    disp(A, n);

    return 0;
}