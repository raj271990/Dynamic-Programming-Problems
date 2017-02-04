// longest palindrome subsequence

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int grtOf(int a, int b) {
    return (a>=b?a:b);
}

// Naive recursive

int lps(char s[], int i, int j) {
    if(i==j) return 1;
    if(s[i] == s[j] && i+1 == j) return 2;
    if(s[i] == s[j]) return lps(s,i+1,j-1) + 2;
    return grtOf(lps(s,i+1,j), lps(s,i,j-1));
}

// bottom up manner - dynamic programming

int lpsdp(char s[], int n) {
    int table[n][n];
    int l,i,j;
    // fill table entries
    for(l=0;l<n;l++) {
        for(i=0,j=l;j<n;i++,j++) {
            if(i==j) table[i][j] = 1;
            else if(s[i] == s[j] && i+1 == j) table[i][j] = 2;
            else if(s[i] == s[j]) table[i][j] = table[i+1][j-1] + 2;
            else table[i][j] = grtOf(table[i+1][j],table[i][j-1]); 
        }
    }
    // print the lsequence
    // length of subsequence is table[0][n-1]
    char lps[table[0][n-1]];
    int start = 0, end = table[0][n-1] - 1;
    i = 0; j=n-1;
    while(i<=j) {
        if(s[i] == s[j]) {
            lps[start++] = s[i];
            lps[end--] = s[j];
            i++;j--;
        }
        else if(table[i][j-1] >= table[i+1][j]) j--;
        else i++;
    }
    // print lps[]
    for(i=0;i<table[0][n-1];i++) printf("%c", lps[i]);
    return table[0][n-1];
}


int main() {
    char s[4] = {'B','B','A','B'};
    //printf("%d", lps(s,0,8));
    printf("\n%d", lpsdp(s,4));
    getchar();
}
