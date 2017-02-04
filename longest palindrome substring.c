// longest palindrome substring

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int grtOf(int a, int b) {
    return (a>=b?a:b);
}

// naive recursive implementation

int lps(char s[], int i, int j) {
    // base
    if(i>j) return 0;
    if(i==j) return 1;
    // recursive
    int curr_len;
    if(s[i] == s[j] && lps(s,i+1,j-1) == j-i-1) curr_len = j-i+1;
    else curr_len = 0;
    if(curr_len != 0) return curr_len;
    else return grtOf(lps(s,i+1,j), lps(s,i,j-1));
}

// dynamic programming - bottom up

int lpsdp(char s[], int n) {
    int table[n][n];
    int i,j,k,max=0,i_max,j_max;
    for(k=0;k<n;k++) {
        for(i=0,j=k;j<n;i++,j++) {
            if(i==j) table[i][j] = 1;
            else if(s[i] == s[j] && i+1 == j) table[i][j] = 2;
            else if(s[i] == s[j] && table[i+1][j-1] + 2 == j-i+1) table[i][j] = j-i+1;
            else table[i][j] = 0;
            
            // compare current val with max
            if(table[i][j] > max) {
                max = table[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }
    // print the longest palindrome substring
    char lps[max];
    int st = 0,e = max-1;
    i=i_max; j=j_max;
    while(i <= j) {
        lps[st++] = lps[e--] = s[i];
        i++; j--;
    }
    for(i=0;i<max;i++) printf("%c", lps[i]);
    return max;
}



int main() {
    char s[16] = {'f','o','r','g','e','e','k','s','s','k','e','e','g','f','o','r'};
    //char s[7] = {'b','a','n','a','n','a','s'};
    //printf("\n%d", lps(s,0,6));
    printf("\n%d", lpsdp(s,16));
    getchar();
}
