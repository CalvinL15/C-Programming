#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50000
 
//PLAY WITH WORDS WITH UNROLLED LINKED LIST
struct Node 
{ 
    int numelements;
    char arr[MAX];
    struct Node *next; 
} ;
 
struct Node *head = NULL; 
 
struct Node* getNode(char data) 
{ 
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->arr[0] = data;
    newNode->next = NULL;
    newNode->numelements = 1;
    return newNode;
} 
 
void locate(int *pos, struct Node **now){ //locates which node pos is at and its array index.
    while(*pos > (*now)->numelements){
        *pos -= (*now)->numelements;
        *now = (*now)->next;
    }
}
 
void merge(struct Node *A, struct Node *B){
    int count = 0;
    while(B->numelements > 0){
        A->arr[A->numelements] = B->arr[count];
        A->numelements++;
        B->numelements--;
        count++;
    }
}
void insertPos(int pos, char data) 
{    
    //locate(&pos, &head);
    if(!head)
        head = getNode(data);
    else
    {
        struct Node *now = head;
        locate(&pos, &now);
        if((now->numelements) >= pos-1){ //this implies that the idx_array where we want to insert 
                                    //value is already occupied, and need to be shifted
            for(int i = (now->numelements)-1; i >= pos; i--) //this takes O(k) time
                now->arr[i+1] = now->arr[i];
            now->arr[pos] = data;
            now->numelements++;        
        }
        else{
            now->arr[pos] = data;
            now->numelements++;    
        }
        if(now->numelements == MAX){
                struct Node *temp = getNode(now->arr[MAX-1]);
                temp->next = now->next;
                now->next = temp;
                now->numelements--;
                if(temp->next != NULL && temp->next->numelements <= (MAX)/2){
                    merge(temp, temp->next);
                    free(temp->next);
                    temp->next = temp->next->next;
                }
        }
 
    } 
}
 
void deletion(int pos)
{
    pos += 1;
    struct Node *now = head;
    locate(&pos, &now);
    pos -= 1;
    if(now->numelements >= pos){
        for(int i = pos; i < (now->numelements)-1; i++)
            now->arr[i] = now->arr[i+1]; 
        now->numelements--;    
    }
    else{
        now->numelements--;
    }
    if(now->next != NULL && now->next->numelements <= (MAX-1)/2 && now->numelements <= (MAX-1)/2){
        merge(now, now->next);
        free(now->next);
        now->next = now->next->next;
    }
}
 
/*int query(int pos, int x){
    struct Node *now = head;
    locate(&pos, &now);
    while(x>0){
        while(pos > now->numelements){
            now = now->next;
            pos = 1;    
        }
        print[count] = now->arr[pos-1];
        count++;
        pos++;
        x--;
    }
} */
char preproc[100000];
 
void traverse(struct Node *n){
    int num = n->numelements;
    int count = 0;
    while(n != NULL){
        strncpy(preproc+count, n->arr, num);
        count+=num;
        n = n->next;    
    }
}
 
int main(){
    char command[7];
    int pos;
    int count = 0;
    char sec_com[6];
    char x[2];
    int flag = -0;
    char forprint[100000];
    while(scanf("%s", command) != EOF){
        if(strcmp(command, "insert") == 0){
            flag = 1;
            scanf("%s %c", sec_com, x);
            if(strcmp(sec_com, "left") == 0)
                insertPos(0, x[0]);
            else if(strcmp(sec_com, "right") == 0)
                insertPos(count, x[0]);
            else {
                int position = atoi(sec_com);
                insertPos(position-1, x[0]);
            }
            count++;        
        }
        else if(strcmp(command, "delete") == 0){
            scanf("%s", sec_com);
            if(strcmp(sec_com, "left") == 0)
                deletion(0);
            else if(strcmp(sec_com, "right") == 0)
                deletion(count-1);
            else deletion(atoi(sec_com)-1);        
            count--;                
        }
    }
  //  printf("%d ", count);
    if(flag == 1)
        traverse(head);
    int len = strlen(preproc);
    int longest = 0;
    int counter = 1;
    char temp[1];
    strncpy(temp, preproc, 1);
    if(strlen(preproc) > 0)
        longest = 1;   
    for(int i = 1; i<len; i++){
        if(strncmp(temp, preproc+i, 1) == 0){
            counter++;
            if(counter > longest)
                longest = counter;
        }
        else{
            counter = 1;
            strncpy(temp, preproc+i, 1);
        }
    }
    strncpy(temp, preproc, 1);
    counter = 1;
    if(longest == 1)
        printf("%c ", preproc[0]);
    for(int i = 0; i<len; i++){
        if(strncmp(temp, preproc+i, 1) == 0){
            counter++;
            if(counter == longest)
                printf("%c ", preproc[i]);
        }
        else{
            counter = 1;
            if(counter == longest)
                printf("%c ", preproc[i]);
            strncpy(temp, preproc+i, 1);
        }
    }
    printf("%d", longest);
}
