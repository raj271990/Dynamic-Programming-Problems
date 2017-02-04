// Submatrix with all 1s
// Naive recursive code

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>


int minOf(int a, int b, int c) {
    int min = a<=b?a:b;
    min = min<=c?min:c;
    return min;
}

updateMaxSize(int *max_size_ref, int *i_max_ref, int *j_max_ref, int curr_size, int i, int j) {
    if(*max_size_ref < curr_size) {
        *max_size_ref = curr_size;
        *i_max_ref = i;
        *j_max_ref = j;
    }
}

// recursive

int _func(int c[][5], int i, int j, int *max_size_ref) {
    if(i<0 || j<0) return 0;
    int curr_size = minOf(_func(c,i-1,j-1,max_size_ref), _func(c,i-1,j,max_size_ref), _func(c,i,j-1,max_size_ref)) + 1;
    if(c[i][j] == 0) curr_size = 0;
    // update max
    if(*max_size_ref < curr_size) *max_size_ref = curr_size;
    // return current size
    return curr_size;
}

/*int func(int c[][5], int m, int n) {
    int table[m][n];
    int i, j;
    int max_size = 0;
    int i_max = -1, j_max = -1;
    bool init_max_size_set = false;
    for(i=0;i<m;i++)  {
        table[i][0] = c[i][0];
        if(!init_max_size_set && table[i][0] == 1) {
            updateMaxSize(&max_size, &i_max, &j_max, table[i][0], i, j);
            init_max_size_set = true;
        }
    }
    for(j=0;j<n;j++) { 
        table[0][j] = c[0][j];
        if(!init_max_size_set && table[0][j] == 1) {
            updateMaxSize(&max_size, &i_max, &j_max, table[0][j], i, j);
            init_max_size_set = true;
        }
    }
    for(i=1;i<m;i++) {
        for(j=1;j<n;j++) {
            if(c[i][j] == 0) table[i][j] = 0;
            else table[i][j] = minOf(table[i-1][j-1], table[i-1][j], table[i][j-1]) + 1;
            // Update maxsize
            updateMaxSize(&max_size, &i_max, &j_max, table[i][j], i, j);
        }
    }
    printf("i_max = %d and j_max = %d\n", i_max, j_max);
    return max_size;
} */

int main() {
    int c[6][5] = {{0,1,1,0,1},
                   {1,1,0,1,0},
                   {0,1,1,1,0},
                   {1,1,1,1,0},
                   {1,1,1,1,1},
                   {0,0,0,0,0}};
    int max_size = INT_MIN;
    //printf("%d", func(c,6,5));
    printf("%d", _func(c,6,5,&max_size));
    printf("max_size = %d", max_size);
    getch();
    return 0;
}
