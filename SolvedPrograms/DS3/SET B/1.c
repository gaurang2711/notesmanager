#include<stdio.h>
#include<string.h>


int main(){
    char name[100][100];
    char nSearch[100];
    int flag = 0;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter name of %d students: \n", n);
    for(int i = 0; i < n; i++){
        printf("Student %d: ", i + 1);
        scanf("%s", name[i]);
    }
    
    printf("Enter name to search: ");
    scanf("%s", nSearch);

    for(int i = 0; i < n; i++){
        if(strcmp(name[i], nSearch) == 0){
            flag  = 1;
            break;
        }
    }

    if(flag == 1){
        printf("\"%s\" is present in the list\n", nSearch);
    }
    else{
        printf("\"%s\" is not present in the list\n", nSearch);
    }

    return 0;
}