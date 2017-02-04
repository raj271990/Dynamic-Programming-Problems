// palindrome partitioning


#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>


bool isPalin(char s[], int i, int j) {
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Naive recursive solution

int palinpartition(char s[], int i, int j) {
    if(i==j || isPalin(s,i,j)) return 0;
    int min_partition = INT_MAX, curr_partition,k;
    for(k=i+1;k<=j;k++) {
        curr_partition = palinpartition(s,i,k-1) + palinpartition(s,k,j) + 1;
        if(curr_partition < min_partition) min_partition = curr_partition;
    }
    return min_partition;
}

// bottom up solution - dynamic programming

int palinPartitiondp(char s[], int n) {
    int table[n][n];
    int l,i,j;
    bool palin[n][n];
    // fill palin table
    for(l=0;l<n;l++) {
        for(i=0,j=l;j<n;i++,j++) {
            palin[i][j] = isPalin(s,i,j)?true:false;
        }
    }
    // fill table[][]
    for(l=0;l<n;l++) {
        for(i=0,j=l;j<n;i++,j++) {
            if(palin[i][j]) table[i][j] = 0;
            else {
                table[i][j] = INT_MAX;
                int k, curr_val;
                for(k=i+1;k<=j;k++) {
                    curr_val = table[i][k-1] + table[k][j] + 1;
                    if(curr_val < table[i][j]) table[i][j] = curr_val;
                }
            }
        }
    }
    return table[0][n-1];
}


int main() {
    char s[14] = {'a','b','a','b','b','b','a','b','b','a','b','a','b','a'};
    printf("%d\n", palinpartition(s,0,13));
    printf("%d", palinPartitiondp(s,14));
    getchar();
}
