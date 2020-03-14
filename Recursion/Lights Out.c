#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
void print_matrix(int n, int m, int arr[][m]) {
	int i,j;
 
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf ("%d ",arr[i][j]);
		}
		printf ("\n");
	}
 
}
 
 
void lights_out(int n, int arr[][(n*n)+1]) {
	int i,j,m;
 
	for (i=0;i<n*n;i++) {
		for (j=0;j<(n*n)+1;j++) {
			arr[i][j] = 0;
		}
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			m = (n*i)+j;
			arr[m][m] = 1;
			if (i > 0) {
				arr[m][m-n]= 1;
			}
			if ((i < (n-1)) && (m+n < n*n)) {
				arr[m][m+n] = 1;
			}
			if (j > 0) {
				arr[m][m-1] = 1;
			}
			if ((j < (n-1)) && (m+1 < n*n)) {
				arr[m][m+1] = 1;
			}
		}
	}
}
 
int nullmatrix(int n, int m, int arr[][m], int **null) {
        int i,j=0;
        int k,l=0;
        int a,b=0;
        int aux[m];
        int temp=0;
        int ipivot = 0;
        int jpivot = 0;
        int rank = 0;
		int nullity=0;
		int zero=0;
		int d,daux=0;
        for (i=0;i<n;i++) {
                if (arr[ipivot][jpivot] != 1) {
                        for (k=ipivot+1;k<n;k++) {
                                if (arr[k][jpivot] != 0) {
                                        memcpy(aux,arr[ipivot],sizeof(aux));
                                        memcpy(arr[ipivot],arr[k],sizeof(aux));
                                        memcpy(arr[k],aux,sizeof(aux));
                                        if (arr[k][jpivot] == 1) {
                                                k = n;
                                        }
                                }
                        }
                }
                if (arr[ipivot][jpivot] == 1) {
                        rank++;
                        for (k=0;k<n;k++) {
                                if (arr[k][jpivot] != 0 && k != ipivot) {
                                        for (l=0;l<m;l++) {
                                                if (arr[k][l]==1 && arr[ipivot][l]==1) { // modulo 2 sum
                                                        arr[k][l]=0;
                                                } else {
                                                        arr[k][l]=arr[k][l]+arr[ipivot][l];
                                                }
                                        }
                                }
                        }
                }
 
                if (arr[ipivot][jpivot] == 0) {
			for (a=0;a<n;a++) {
				if (nullity == 0) {
					null[a]=malloc(sizeof(int));
				} else {
					null[a]=realloc(null[a],(sizeof(int)*(nullity+1)));
				}
				null[a][nullity] = arr[a][jpivot];
			}
			
                        jpivot++;
			nullity++;
                } else {
                        ipivot++;
                        jpivot++;
                }
        }
 
	d = n - rank;
	daux = d;
	for (a=0;a<d;a++) {
		for (b=0;b<d;b++) {
			if (a==b) {
				null[n-daux][a]=1;
				daux--;
			}
		}
	}
 
	return(rank);
 
}
 
void solve(int a, int **B) {
 
	int i,j,l,k=0;
	int arr[a*a][(a*a)+1];
	int final[a][a];
	int B_aux[a*a];
	int rank=0;
	int ones=0;
	int ones_aux= -1;
	int minimum = -1;
	int **d = malloc(a * a * sizeof(int *));
	int dsize = 0;
	int temp=0;
	int solution=1;
 
	lights_out(a,arr);
	l=0;
	for (i=0;i<a;i++) {
		for (j=0;j<a;j++) {
			arr[l][a*a]=B[i][j];
			B_aux[l++]=B[i][j];
		}
	}
	rank = nullmatrix(a*a,(a*a)+1,arr,d);
	
	for (i=0;i<a*a;i++) {
		temp=0;
		for (j=0;j<(a*a)+1;j++) {
			if (j != ((a*a))) {
				temp+=arr[i][j];
			} else {
				if ((temp == 0) && (arr[i][j] == 1)) {
					solution = -1;
				}
			}
		}
	}
 
	if (solution == -1) {
		printf ("There is no solution\n");
		free(d);
	} else {	
	
		if (((a*a)-rank) != 0) {
			if (((a*a)-rank) == 1) {
				dsize = 1;
			} else {
				dsize = 2;
			}
			for (i=0;i<a*a;i++) {
				d[i]=realloc(d[i],(sizeof(int)*((a*a)-rank+dsize)));
				d[i][(a*a)-rank]=0;
				d[i][(a*a)-rank+1]=0;
			}
		} else {
			dsize = 0;
			for (i=0;i<a*a;i++) {
				d[i]=malloc(sizeof(int));
			}
		}
		for (i=0;i<(a*a);i++) {
		d[i][(a*a)-rank] = arr[i][a*a];
			for (j=0;j<(a*a)-rank;j++) {
				if (j == 0) {
					for (k=0;k<(a*a)-rank+1;k++) {
						d[i][(a*a)-rank+1]+=d[i][k];
					}
					d[i][(a*a)-rank+1] = d[i][(a*a)-rank+1] % 2;
				} 
				if (d[i][j] == 1 && arr[i][a*a] == 1) {
					d[i][j] = 0;
				} else {
					d[i][j]=d[i][j] + arr[i][a*a];
				}
				
			}
		}
		if (dsize == 0) {
			minimum = 0;
			for (i=0;i<a*a;i++) {
				if (d[i][0] == 1) {
					ones++;
				}
			}
			ones_aux = ones;
		}
		for (k=0;k<(a*a)-rank+dsize;k++) {
			ones=0;
			for (i=0;i<a*a;i++) {
				if (d[i][k] == 1) {
					ones++;
				}
			}
			if (ones_aux > ones) {
				minimum = k;
				ones_aux = ones;
			} else {
				if (ones_aux == -1) {
					ones_aux = ones;
					minimum = k;
				}
			}
		}
		printf ("%d\n",ones_aux);
		l=0;
		for (i=0;i<a;i++) {
			for (j=0;j<a;j++) {
				final[i][j]=d[l++][minimum];
				if (final[i][j] == 1) {
					printf ("%d %d\n",i+1,j+1);
				}
			}
		}
		free(d);
	}		
}
 
int main() {
	int a,T=0;
	int b,c,e=0;
	int **B;
	char number[30];
	scanf("%d",&a);
	B = malloc(a * sizeof(int *));
	//for (c=0;c<a;c++) {
	//	B[c] = malloc(a * sizeof(int));
	//	scanf("%s",number);
	//	for (e=0;e<a;e++) {
	//		B[c][e] = number[e] - '0';
	//	}
	//	number[0]='\0';
	//}
	for(int i = 0; i<a; i++)
		for(int j = 0; j<a; j++)
			scanf("%d", B[i][j]);
	solve(a,B);
	free(B);
	return(0);
}   
