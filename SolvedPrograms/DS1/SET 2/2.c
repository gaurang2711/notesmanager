#include<stdio.h>
#include<string.h>

struct emp{
    int id;
    int age;
};

void printerOP(struct emp e[], int n){
    for(int i = 0; i < n; i++){
        printf("ID: %d\nAGE: %d\n", e[i].id, e[i].age);
    }
}

void partition(){
    printf("\n-----------------------------------------------------\n");
}

void sorter(struct emp e[], int n){
    struct emp key;
    int i, j;
    for(i = 1; i < n; i++){
        key = e[i];
        j = i - 1;
        while (j >= 0 && e[j].age > key.age)
        {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = key;

    }
}

int main(){
    FILE *fp;
    int count = 0;
    struct emp e[100];

    fp = fopen("emp.txt", "r");

    if(fp == NULL){
        printf("\nERROR IN FILE\n");
        return -1;
    }

    while(fscanf(fp, "%d %d", &e[count].id, &e[count].age) == 2){
        count++;
        if(count >= 100){
            printf("MAXIMUM CHAR REACHED\n");
            break;
        }
    }

    fclose(fp);

    if(fp == NULL){
        printf("FILE IS EMPTY\n");
        return 0;
    }


    partition();
    printf("BEFORE SORT\n");
    printerOP(e, count);
    sorter(e, count);
    printf("AFTER SORT\n");
    partition();
    printerOP(e, count);

    return 0;

}