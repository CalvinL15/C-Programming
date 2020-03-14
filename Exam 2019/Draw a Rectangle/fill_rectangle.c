#include <stdio.h>
#include <string.h>
#include "fill_rectangle.h"

void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
 
    int r=0,c=0;
    int *up = upper_left;
    int *bot = bottom_right; 
    while(up<bot){
        up+=n_row;
        if(up>bot){
            up-=n_row;
            break;
        }
        if(up>=bot){
            r++;
            break;
        }
        r++;
    }
    while(up<bot){
        up++;
        if(up>bot){
            up--;
            break;
        }
        if(up>=bot){
            c++;
            break;
        }
        c++;
    }
    up = upper_left;
    bot = bottom_right;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            *up = fill;
            up++;
        }
        up = up + (n_row - c-1);
    }
}

void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
	int r=0,c=0;
    int *up = upper_right;
    int *bot = bottom_left; 
    while(up<bot){ 
        bot-=n_col;
        if(up>bot){
        	r++;
            break;
        }
        if(up>=bot){
            r++;
            break;
        }
        r++;
    }
	if(up!=bot){
		c = up - bot;
	}
    up = upper_right;
    bot = bottom_left;
    for(int i=0;i<=c;i++){
        bot = bottom_left;
		bot = bot + i;
		for(int j=0;j<=r;j++){
            *bot = fill;
            if(j==r)break;
            bot = bot - n_col;
        }
    }
}
