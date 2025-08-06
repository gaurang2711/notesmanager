#include<stdio.h>
#include<string.h>

#define MAX_CITIES 10
#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10

int main(){
    FILE *fp;
    char cities[MAX_CITIES][MAX_NAME_LENGTH];
    char std_code[MAX_CITIES][MAX_CODE_LENGTH];
    char search_city[MAX_NAME_LENGTH];
    int flag = 0;

    fp = fopen("cities.txt", "r");
    if(fp == NULL){
        printf("\"cities.txt\" not found\n");
        return 1;
    }

    for(int i = 0; i < MAX_CITIES; i++){
        fscanf(fp, "%s %s", cities[i], std_code[i]);
    }
    fclose(fp);

    printf("Enter the city name to search: ");
    scanf("%s", &search_city);

    for(int i = 0; i < MAX_CITIES; i++){
        if(strcmp(cities[i], search_city) == 0){
            printf("The STD Code for %s is: %s\n", search_city, std_code[i]);
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("\"%s\" is not in the list.\n", search_city);
    }

    return 0;
}