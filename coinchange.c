// coin change problem

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// Naive recursive
int coinchange(int N, int s[], int i) {
    if(N==0) return 1;
    if(i<0 || N<0) return 0;
    return coinchange(N,s,i-1) + coinchange(N-s[i],s,i);
}

// bottom up approach

int coinchangedp(int N, int s[], int m) {
    int table[m+1][N+1];
    int i,j;
    for(i=0;i<m+1;i++) {
        for(j=0;j<N+1;j++) {
            if(j==0) table[i][j] = 1;
            else if(i==0 && j>0) table[i][j] = 0;
            else if(s[i-1] > j) table[i][j] = table[i-1][j];
            else table[i][j] = table[i-1][j] + table[i][j-s[i-1]];
        }
    }
    return table[m][N];
}


int main() {
    int N = 10;
    int s[4] = {2,5,3,6};
    //printf("%d", coinchange(N,s,3));
    printf("%d", coinchangedp(N,s,4));
    getchar();
}
