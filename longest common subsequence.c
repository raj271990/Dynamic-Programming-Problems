// longest common subsequence


#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int grtOf(int a, int b) {
    return (a>=b?a:b);
}

int lcs(char s1[], int i, char s2[], int j) {
    // base
    if(i<0 || j<0) return 0;
    // recursive
    if(s1[i] == s2[j]) return lcs(s1,i-1,s2,j-1) + 1;
    return grtOf(lcs(s1,i-1,s2,j),lcs(s1,i,s2,j-1));
}



int main() {
    char s1[4] = {'l', 'c', 'l', 'c'};
    char s2[4] = {'c', 'l', 'c', 'l'};
    printf("%d", lcs(s1,3,s2,3));
    getch();
    return 0;
}
