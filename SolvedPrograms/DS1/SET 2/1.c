#include<stdio.h>
#include<string.h>

struct student{
    int roll;
    char name[100];
};

void printerOP(struct student arr[], int n){
    for(int i = 0; i < n; i++){
        printf("Roll: %d\nName: %s\n", arr[i].roll, arr[i].name);
    }
}

void partition(){
    printf("\n--------------------------------------------\n");
}

void buBBler(struct student s[], int n){
    struct student temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strcmp(s[j].name, s[j + 1].name) > 0){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main(){
    FILE *fp;
    struct student s[100];
    int count = 0;

    fp = fopen("studinfo.txt", "r");

    if(fp == NULL){
        printf("ERROR IN FILE\n");
        return -1;
    }

    while(fscanf(fp, "%d %[^\n]", &s[count].roll, &s[count].name) == 2){
        count++;
        if(count >= 100){
            printf("MAXIMUM CHARACTER LIMIT REACHED\n");
            break;
        }
    }

    fclose(fp);

    if(count == 0){
        printf("\nFile is empty\n");
    }

    printf("BEFORE SORT\n");
    printerOP(s, count);
    partition();
    buBBler(s, count);
    partition();
    printerOP(s, count);

    return 0;
    
}