// minimum edit distance

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int minOf(int a, int b, int c) {
    int min = a<=b?a:b;
    min = min<=c?min:c;
    return min;
}

// Naive recursive approach

/*
int minEditDist(char s1[], int i, char s2[], int j) {
    if(i<0 && j<0) return 0;
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(s1[i] == s2[j]) return minEditDist(s1,i-1,s2,j-1);
    return minOf(minEditDist(s1,i-1,s2,j), minEditDist(s1,i,s2,j-1), minEditDist(s1,i-1,s2,j-1)) + 1;
}
*/

// bottom up approach

int minEditDist(char s1[], int m, char s2[], int n) {
    int table[m+1][n+1];
    int i,j;
    for(i=0;i<m+1;i++) table[i][0] = i;
    for(j=0;j<n+1;j++) table[0][j] = j;
    for(i=1;i<m+1;i++) {
        for(j=1;j<n+1;j++) {
            if(s1[i-1] == s2[j-1]) table[i][j] = table[i-1][j-1];
            else table[i][j] = minOf(table[i][j-1], table[i-1][j], table[i-1][j-1]) + 1;
        }
    }
    return table[m][n];            
}


int main() {
    char s1[6] = {'k', 'i', 't', 't', 'e', 'n'};
    char s2[7] = {'s', 'i', 't', 't', 'i', 'n', 'g'};
    printf("%d", minEditDist(s1,5,s2,6));
    getch();
    return 0;
}
