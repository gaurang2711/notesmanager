     #include<stdio.h>

    struct emp
    {
        int id;
        int age;
    };

    void printFunc(struct emp *e, int n){
        for(int i = 0; i < n; i++){
            printf("ID: [%d]\tAge: [%d]\n", e[i].id, e[i].age);
        }
    }

    void insSort(struct emp *e, int n){
        int i, j;
        struct emp key;
        for(i = 1; i < n; i++){
            key = e[i];
            j = i - 1;
            while(j >= 0 && e[j].age > key.age){
                e[j + 1] = e[j];
                j--;
            }
            e[j + 1] = key;
        }
    }

    int main(){
        struct emp e[100];
        int n = 0;
        FILE *fp;

        fp = fopen("emp.txt", "r");

        if(fp == NULL){
            printf("No such file\n");
            return -1;
        }

        while (fscanf(fp, "%d %d", &e[n].id, &e[n].age) == 2)
        {
            n++;
            if(n >= 100){
                printf("No more employees\n");
                break;
            }
        }

        fclose(fp);

        if(n == 0){
            printf("No empoyee\n");
            return 1;
        }

        printf("\nBefore Sort\n");
        printFunc(e, n);
        insSort(e, n);
        printf("After Sort\n");
        printFunc(e, n);
        
        printf("\n--CODED BY GAURANG DALAL--\n");
    }