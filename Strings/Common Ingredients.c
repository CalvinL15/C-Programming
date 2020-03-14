#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    char food[65];
    char ingredient[11][65];
    int ing;    
} component;
 
void selectionSort(char arr[][65], int n) 
{ 
    int i, j, min_idx; 
    char minStr[65]; 
    for (i = 0; i < n-1; i++) 
    { 
        int min_idx = i; 
        strcpy(minStr, arr[i]); 
        for (j = i+1; j < n; j++) 
        { 
            if (strcmp(minStr, arr[j]) > 0) 
            { 
                strcpy(minStr, arr[j]); 
                min_idx = j; 
            } 
        } 
        if (min_idx != i) 
        { 
            char temp[65]; 
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min_idx]); 
            strcpy(arr[min_idx], temp); 
        } 
    } 
}
 
int main(){
    int N;
    scanf("%d", &N);
    component foods[N];
    for(int i = 0; i<N; i++){
        scanf("%s", foods[i].food);
        scanf("%d", &foods[i].ing);
        for(int j = 0; j<foods[i].ing; j++)
            scanf("%s", foods[i].ingredient[j]);
        selectionSort(foods[i].ingredient, foods[i].ing);    
    //    qsort(foods[i].ingredient, foods[i].ing, sizeof(char), myCompare);    
    }
    int M;
    scanf("%d", &M);
    char temp1[64], temp2[64];
    for(int i = 0; i<M; i++){
        scanf("%s %s", temp1, temp2);
        int flag = 0, x = 0, y = 0;
        for(int j = 0; j<N; j++){
            if(strcmp(temp1, foods[j].food) == 0)
                x = j, flag++;
            else if(strcmp(temp2, foods[j].food) == 0)
                y = j, flag++;
            if(flag == 2) break;        
        } 
        int f2 = 0;
        char temp3[10][65];
        int count = 0;
        for(int k = 0; k<foods[x].ing; k++){
            for(int l = 0; l<foods[y].ing; l++){
                if(strcmp(foods[x].ingredient[k], foods[y].ingredient[l]) == 0){
                    if(f2 == 0)
                        printf("%s", foods[x].ingredient[k]);
                    else printf(" %s", foods[x].ingredient[k]);    
                    f2 = 1;
                //    strcpy(temp3[count], foods[x].ingredient[k]);
                 //   count++;
                }
            }
        } 
        if(f2 == 0) printf("nothing");
    //    else {
    //        selectionSort(temp3, count);
    //        for(int x = 0; x<count; x++){
    //            printf("%s", temp3[x]);
    //            if(x!=count-1) printf(" ");
    //        }
     //   }
        if(i != M-1) printf("\n");
    }
    return 0;
}
