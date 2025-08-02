#include<stdio.h>
#include<string.h>

struct stud
{
    int roll;
    char name[100];
};

void bubSort(struct stud s[], int n)
{
    struct stud temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(strcmp(s[j].name, s[j + 1].name) > 0){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void printerOP(struct stud s[], int n){
    for(int i = 0; i < n; i++){
        printf("Roll: [%d]\tName: [%s]\n", s[i].roll, s[i].name);
    }
}

void partition(){
    printf("\n________________________________________________________________________\n");
}

int main(){
    FILE *fp;
    int n = 0;
    struct stud s[100];

    fp = fopen("studinfo.txt", "r");

    if(fp == NULL){
        printf("There is something error in file\n");
        return -1;
    }

    while (fscanf(fp, "%d %[^\n]", &s[n].roll, &s[n].name) == 2)
    {
        n++;
        if(n >= 100){
            printf("Maximum level reached\n");
            break;
        }
    }

    fclose(fp);
    
    printf("\nBefore Sort\n");
    printerOP(s, n);
    bubSort(s, n);
    partition();
    printf("\nAfter Sort\n");
    printerOP(s, n);

        printf("\n//Coded by Gaurang Dalal; SY BCA\n");
    return 0;

}