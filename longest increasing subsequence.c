// longest increasing subsequence

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// naive recursive approach
/*
int lis(int a[], int i, int *max) {
    // Base
    if(i == 0) return 1;
    // Recursive
    int curr = 1,j;
    for(j=i-1;j>=0;j--) {
        if(a[j] < a[i]) {
            int x = 1+lis(a,j,max);
            if(x > curr) curr = x;
        }
    }
    if(curr > *max) *max = curr;
    return curr;
}
*/

// bottom up approach - dynamic programing

int lis(int a[], int n) {
    int table[n];
    int max=1;
    int i,j;
    for(i=0;i<n;i++) table[i] = 1;
    for(i=1;i<n;i++) {
        for(j=i-1;j>=0;j--) {
            if(a[j] < a[i] && 1+table[j] > table[i]) {
                table[i] = 1+table[j];
            }
        }
        if(table[i] > max) max = table[i];
    }
    return max;
}

int main() {
    int a[9] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int max = 1;
    //int x = lis(a,8,&max);
    //printf("%d", max);
    printf("%d", lis(a,9));
    getchar();
}
