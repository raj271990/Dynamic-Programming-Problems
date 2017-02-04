// Minimum jumps to reach end

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// Naive recursive code
/*
int jumps(int a[], int i, int n) {
    if(i==n) return 0;
    if(a[i] == 0) return INT_MAX;
    int j, jumps_curr_pos, min_jumps = INT_MAX;
    for(j=i+1;j<=i+a[i] && j<=n;j++) {
         jumps_curr_pos = jumps(a,j,n);
         if(jumps_curr_pos != INT_MAX && min_jumps > (jumps_curr_pos + 1)) min_jumps = jumps_curr_pos + 1;
    }
    return min_jumps;
}
*/
// dp solution

int jumps(int a[], int n) {
    int table[n];
    table[n-1] = 0;
    int i,j;
    for(i=n-2;i>=0;i--) {
        table[i] = INT_MAX;
        for(j=i+1;j<=i+a[i] && j<n;j++) {
            if(table[j] != INT_MAX && table[j] + 1 < table[i]) table[i] = table[j] + 1;
        }
    }
    return table[0];
}


int main() {
    int a[11] = {1,3,5,8,9,2,6,7,6,8,9};
    //printf("%d", jumps(a,0,10));
    printf("%d", jumps(a,11));
    getch();
    return 0;
}
