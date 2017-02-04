// optimal strategy for a game

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int grtOf(int a, int b) {
    return (a>=b?a:b);
}

int lsrOf(int a, int b) {
    return a<=b?a:b;
}


// Naive recursive solution

int f(int v[], int i, int j) {
    if(i+1 == j) return grtOf(v[i], v[j]);
    return grtOf(v[i] + lsrOf(f(v,i+2,j), f(v,i+1,j-1)),
               v[j] + lsrOf(f(v,i+1,j-1), f(v,i,j-2)));
}

// bottom up approach - dynamic programming

int optGameStr(int v[], int n) {
    int table[n][n];
    int i,j,k;
    for(k=1;k<n;k=k+2) {
        for(i=0,j=i+k;j<n;i++,j++) {
            if(i+1==j) table[i][j] = grtOf(v[i], v[j]);
            else {
                table[i][j] = grtOf(v[i] + lsrOf(table[i+2][j], table[i+1][j-1]),
                                    v[j] + lsrOf(table[i+1][j-1], table[i][j-2]));
            }
        }
    }
    return table[0][n-1];
}


int main() {
    int v[4] = {8,15,3,7};
    printf("%d\n", f(v,0,3));
    printf("%d", optGameStr(v,4));
    getchar();
}
