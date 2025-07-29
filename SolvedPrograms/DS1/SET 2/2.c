#include<stdio.h>

struct emp{
    int id;
    int age;
};

void printFunc(struct emp arr[], int n){
    for(int i = 0; i < n; i++){
        printf("ID: %d\nAge: %d\n", arr[i].id, arr[i].age);
    }
}

void partition(){
    printf("\n------------------------------------------------\n");
}

void insSort(struct emp arr[], int n){
    int i, j;
    struct emp key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j].age > key.age){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    FILE *fp;
    int count = 0;
    struct emp e[100];

    fp = fopen("emp.txt", "r");
    if(fp == NULL){
        printf("Error occured\n");
        return -1;
    }

    while(fscanf(fp, "%d %d", &e[count].id, &e[count].age) == 2)
    {
        count++;
        if(count >= 100){
            printf("Maximum character reached\n");
            break;
        }
    }

    fclose(fp);

    if(count == 0){
        printf("File is empty\n");
        return 0;
    }

    printf("BEFORE SORTING\n");

    partition();
    printFunc(e, count);
    partition();
    insSort(e, count);
    partition();
    printFunc(e, count);

    return 0;
}