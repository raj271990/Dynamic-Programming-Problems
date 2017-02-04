// number of decodings of a digit sequence

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

/*
int ndecodes(char d[], int i) {
    if(i<=0) return 1;
    int count=0;
    if(d[i] > '0') count+= ndecodes(d,i-1);
    if(d[i-1] == '1' || (d[i-1] == '2' && d[i] < '7' )) count += ndecodes(d,i-2);
    return count;
}
*/

// bottom up implementation

int ndecodesdp(char d[], int n) {
    int table[n+1];
    int i;
    table[0] = table[1] = 1;
    for(i=2;i<=n;i++) table[i] = 0;
    for(i=2;i<=n;i++) {
        if(d[i-1] > '0') table[i] += table[i-1];
        if(d[i-2] == '1' || (d[i-2] == '2' && d[i-1] < '7')) table[i] += table[i-2];
    }
    return table[n];
}


int main() {
    char d[4] = {'1','1','2','0'};
    //printf("%d/n", ndecodes(d,3));
    printf("%d", ndecodesdp(d,4));
    getchar();
}
