#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Data{
    char name[64];
    int height;
    int weight;
    double BMI;
} data;
 
int cmp(const void *a, const void *b){
    data *x = (data *)a;
    data *y = (data *)b;
    if(x->BMI > y->BMI)
        return 1;
    else if(x->BMI < y->BMI)
        return -1;
    if(x->weight > y->weight)
        return 1;
    else if(x->weight < y->weight)
        return -1;    
    if(x->height > y->height)
        return 1;
    else if(x->height < y->height)
        return -1;    
    if(strcmp(x->name, y->name) < 0)
        return -1;
    else return 1;    
}
 
int main(){
    int N;
    scanf("%d", &N);
    data D[N];
    for(int i = 0; i<N; i++){
        scanf("%s %d %d", D[i].name, &D[i].height, &D[i].weight);
        D[i].BMI = (double)D[i].weight / ((double)D[i].height * (double)D[i].height);
    }
    qsort(D, N, sizeof(data), cmp);
    for(int i = 0; i<N; i++){
        printf("%s %d %d\n", D[i].name, D[i].height, D[i].weight);
    }
    return 0;
}
