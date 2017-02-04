// longest common substring 

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int grtOf(int a, int b) {
    return (a>b?a:b);
}


int lcsuff(char s1[], int m, char s2[], int n) {
    int table[m+1][n+1];
    int i,j;
    int max_so_far =0, i_max, j_max;
    for(i=0;i<m+1;i++) {
        for(j=0;j<n+1;j++) {
            if(i==0 || j==0) table[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = 0;
            if(max_so_far < table[i][j]) {
                max_so_far = table[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }
    // print lcs
    i=i_max - max_so_far;
    while(i<i_max) {
        printf("%c", s1[i]);
        i++;
    }
    return max_so_far;
}

int main() {
    char s1[9] = {'z','x','a','b','c','d','e','z','y'};
    char s2[9] = {'y','z','a','b','c','d','e','z','x'};
    printf("\n%d", lcsuff(s1,9,s2,9));
    getchar();
    return 0;
}
