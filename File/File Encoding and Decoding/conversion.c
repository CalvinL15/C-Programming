#include "conversion.h"
#include <stdlib.h>
#include <stdio.h>
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
 
void bin2ascii(char input_file[32], char output_file[32], char dict[17]){
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");
    long sz = getsize(input_file);
    for(int i = 0; i<sz; i++){
        unsigned char temp;
        fread(&temp, sizeof(unsigned char), 1, fin);
        unsigned char x = temp >> 4;
        unsigned char y = temp << 4;
        y >>= 4;
        fwrite(&dict[x], 1, sizeof(unsigned char), fout);
        fwrite(&dict[y], 1, sizeof(unsigned char), fout);    
    }
    fclose(fin);
    fclose(fout);
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17]) {
    int i, k = 0;
    FILE* fin = fopen(input_file, "r");
    FILE* fout = fopen(output_file, "wb");
    fseek(fin, 0, SEEK_END);
    int size = ftell(fin);
    fseek(fin, 0, SEEK_SET);
    char temp1, temp2;
    while (k < size) {
        fread(&temp1, 1, sizeof(char), fin);
        fread(&temp2, 1, sizeof(char), fin);
        unsigned char encoded = 0;
        unsigned char id1 = 0, id2 = 0;
        for (i = 0; i < 17; i++) {
            if (dict[i] == temp1) 
                id1 = i;
            if (dict[i] == temp2)
                id2 = i;
        }
        id1 <<= 4;
        encoded = id1;
        encoded |= id2;
        fwrite(&encoded, 1, sizeof(char), fout);
        k+=2;    
    }
    fclose(fin);
    fclose(fout);
}
