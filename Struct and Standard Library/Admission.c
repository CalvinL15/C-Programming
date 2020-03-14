#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 
typedef struct{
    int id;
    int math, english, chinese, science, socstudy;
    int total;
} Students;
 
int cmp(const void *a,const void *b){
    Students *x = (Students *)a;
    Students *y = (Students *)b;
    if (x->total<y->total)return 1;
    if (x->total>y->total)return -1;
    if (x->math<y->math)return 1;
    if (x->math>y->math)return -1;
    if (x->english<y->english)return 1;
    if (x->english>y->english)return -1;
    if (x->science<y->science)return 1;
    if (x->science>y->science)return -1;
    if (x->chinese<y->chinese)return 1;
    if (x->chinese>y->chinese)return -1;
    if (x->socstudy<y->socstudy)return 1;
    if (x->socstudy>y->socstudy)return -1;
    return 0;
}
int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    Students data[N];
    for(int i = 0; i<N; i++){
        scanf("%d %d %d %d %d %d", &data[i].id, &data[i].chinese, &data[i].english, &data[i].math, &data[i].science, &data[i].socstudy);
        data[i].total = data[i].chinese + data[i].english + data[i].science + data[i].math + data[i].socstudy;
    }
    qsort(data, N, sizeof(Students), cmp);
    int count = 0;
    while(M--){
        printf("%d\n", data[count].id);
        count++;
    }
    int flag = 0;
    while(flag == 0){
        if(data[count].chinese == data[count-1].chinese && data[count].english == data[count-1].english && data[count].math == data[count-1].math && data[count].science == data[count-1].science && data[count].socstudy == data[count-1].socstudy){
            printf("%d\n", data[count].id);
            count++;
        }
        else flag = 1; 
    }
}
