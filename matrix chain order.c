// matrix chain multiplication

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// naive recursive implementation
/*
int matchainorder(int p[], int i, int j) {
    if(i+1 == j) return 0;
    int k, min_till_now, min_so_far = INT_MAX;
    for(k=i+1;k<j;k++) {
        min_till_now = matchainorder(p,i,k) +
                       matchainorder(p,k,j) +
                       p[i] * p[k] * p[j];
        if(min_till_now < min_so_far)
            min_so_far = min_till_now;
    }
    return min_so_far;
}
*/


// bottom up approach

int matchainorder(int p[], int n) {
    int table[n][n];
    int l,i,j,k;
    int x;
    for(l=1;l<n;l++) {
        for(i=0,j=l;j<n;i++,j++) {
            if(i+1 == j) table[i][j] = 0;
            else {
                table[i][j] = INT_MAX;
                for(k=i+1;k<j;k++) {
                    x = table[i][k] + table[k][j] + p[i]*p[k]*p[j];
                    if(x<table[i][j]) table[i][j] = x;
                }
            }
        }
    }
    return table[0][n-1];
}


int main() {
    int p[5] = {10, 20, 30};
    //printf("%d", matchainorder(p,0,2));
    printf("%d", matchainorder(p,3));
    getchar();
}
