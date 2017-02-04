// Subset sum

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// Naive recursive

/* bool doesSubsetExists(int a[], int i, int sum) {
    if(sum == 0) return true;
    if(sum < 0) return false;
    if(i<0 && sum >0) return false;
    return doesSubsetExists(a,i-1,sum-a[i]) | doesSubsetExists(a,i-1,sum);
} */

// bottom up approach

bool doesSubsetExists(int a[], int n, int s) {
    int table[n+1][s+1];
    int i,j;
    for(i=0 ;i<n+1;i++) table[i][0] = 1;
    for(j=1;j<s+1;j++) table[0][j] = 0;
    for(i=1;i<n+1;i++) {
        for(j=1;j<s+1;j++) {
            if(j<a[i-1]) table[i][j] = table[i-1][j];
            else table[i][j] = table[i-1][j] | table[i-1][j-a[i-1]];
            }
    }
    return table[n][s];
}


int main() {
    int a[4] = {1,3,9,2};
    printf("%d", doesSubsetExists(a,4,100));
    getch();
    return 0;
}
