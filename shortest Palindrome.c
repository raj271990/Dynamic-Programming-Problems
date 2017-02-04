// Shortest palindrome

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int lsrOf(int a, int b) {
    return a<=b?a:b;
}

// naive recursive 
/*
int minInsertsForPalin(char s[], int i, int j) {
    //base
    if(i>=j) return 0;
    // recursive
    if(s[i] == s[j]) return minInsertsForPalin(s,i+1,j-1);
    return lsrOf(minInsertsForPalin(s,i+1,j), minInsertsForPalin(s,i,j-1)) + 1;
}
*/
// dynamic programming solution

int minInsertsForPalin(char s[], int n) {
    int table[n][n];
    int i,j,k;
    // fill initial entries
    for(k=0;k<=n-1;k++) {
        for(j=0,i=j+k;i<=n-1;i++,j++) {
            table[i][j] = 0;
        }
    }
    // fill dependent entries
    for(k=1;k<=n-1;k++) {
        for(i=0,j=i+k;j<=n-1;i++,j++) {
            if(s[i] == s[j]) table[i][j] = table[i+1][j-1];
            else table[i][j] = lsrOf(table[i+1][j], table[i][j-1]) + 1;
        }
    }
    // return final computation
    return table[0][n-1];    
}


int main() {
    char s[5] = {'a', 'b', 'c', 'd','e'};
    //printf("%d", minInsertsForPalin(s,0,4));
    printf("%d", minInsertsForPalin(s,5));
    getchar();
}


