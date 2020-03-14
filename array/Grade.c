#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    int n, r, w;
    int score = 0;
    scanf("%d %d %d", &n, &r, &w);
    char key_ans[5];
    char students_ans[5];
    int marker[n][5];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++)
            marker[i][j] = 0;
    }
    for(int i = 0; i<n; i++){
        scanf("%s", key_ans);
        int len = strlen(key_ans);
        for(int j = 0; j<len; j++){
            if(key_ans[j] == 'A' || key_ans[j] == 'a')
                marker[i][0]++;
            else if(key_ans[j] == 'B' || key_ans[j] == 'b')
                marker[i][1]++;
            else if(key_ans[j] == 'C' || key_ans[j] == 'c')
                marker[i][2]++;
            else if(key_ans[j] == 'D' || key_ans[j] == 'd')
                marker[i][3]++;
            else marker[i][4]++;                
        }
    }
    int t;
    int arr[5] ={0};
    scanf("%d", &t);
    for(int i = 0; i<t; i++){
        if(i!=0)
            printf("\n");
        for(int j = 0; j<n; j++){
            scanf("%s", students_ans);
            if(strcmp("N/A", students_ans) == 0)
                continue;
            int length = strlen(students_ans);
            for(int k = 0; k<length; k++){
                if(students_ans[k] == 'A' || students_ans[k] == 'a')
                    arr[0]++;
                else if(students_ans[k] == 'B' || students_ans[k] == 'b')
                    arr[1]++;
                else if(students_ans[k] == 'C' || students_ans[k] == 'c')
                    arr[2]++;
                else if(students_ans[k] == 'D' || students_ans[k] == 'd')
                    arr[3]++;
                else if(students_ans[k] == 'E' || students_ans[k] == 'e')
                    arr[4]++;                
            }
            if(arr[0] == marker[j][0] && arr[1] == marker[j][1] && arr[2] == marker[j][2] && arr[3] == marker[j][3] && arr[4] == marker[j][4])
                score += r;
            else score -= w;
            for(int x = 0; x<=4; x++)
                arr[x] = 0;    
        }
        if(score < 0)
            score = 0;
        printf("%d", score);
        score = 0;    
    }    
}
