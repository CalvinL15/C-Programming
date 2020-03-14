#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int cnt[11];
 
long getsize(const char *filename){
    long size;
    FILE *f;
    f = fopen(filename, "rb");
    if(f == NULL) return -1;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    fclose(f);
    return size;
}
 
int init(){
    for(int i = 0; i<=10; i++)
        cnt[i] = 0;
}
int getindex(int n){
    int i = -1;
    int min = 1000000;
    for(int x = 1; x<=n; x++){
        if(cnt[x] < min){
            min = cnt[x];
            i = x;
        }
    }
    return i;
}
 
int main(){
    init();
    char fn1[50], prefix[55];
    char suffix[11][3] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    char outname[12][55];
    int n;
    scanf("%s %d %s", fn1, &n, prefix);
    for(int i = 1; i<=n; i++){
        strcpy(outname[i], prefix);
        strcat(outname[i], suffix[i]);
    }
    FILE *f = fopen(fn1, "rb");
    FILE *fptr;
    for(int i = 1; i<=n; i++){
        fptr = fopen(outname[i], "wb");
        fclose(fptr);
    }
    long sz = getsize(fn1);
    int count = 0;
    int idx = 1;
    for(int i = 0; i<sz; i++){
        fptr = fopen(outname[idx], "ab");
        unsigned char buf;
        fread(&buf, sizeof(unsigned char), 1, f);
        if(buf != 255){
            count++;
            fwrite(&buf, sizeof(unsigned char), 1, fptr);
        }
        else if(buf == 255){
            cnt[idx] += count;
            count = 0;
            idx = getindex(n);
        }
        fclose(fptr);
    }
    fclose(f);
    fclose(fptr);
}
