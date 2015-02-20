#include<stdio.h>

main(){
    int ** cycles = new int * [1000];
    for( int i = 0; i< 1000; i++){
            cycles[i] = new int [1000];
            for( int j = 0; j < 1000; j++)
                cycles[i][j] = -1;
    }
    int n;
    scanf("%d", &n);
    int * check = new int[n+1];
    int * perm = new int[n+1];
    for( int i = 1; i < n+1; i++){
        scanf("%d", perm + i);
        check[i] = 0;
    }
    int numcycles = 0;
    for( int count  = 1; count < n+1; count++){
        if( check[count] == -1) continue;
        check[count] = -1;
        cycles[numcycles][0] = count;
        int dummy = perm[count];
        int x = 0;
        while (dummy != cycles[numcycles][0]){
            cycles[numcycles][++x] = dummy;
            check[dummy] = -1;
            dummy = perm[dummy];
        }
        cycles[numcycles][++x] = dummy;
        numcycles ++;
    }
    printf("%d\n",numcycles);
    for( int i = 0; i < numcycles; i++){
        int j = 0;
        while( cycles[i][j] != -1){
            printf("%d", cycles[i][j]);
            printf(" ");
            j++;
        }
        printf("\n");
    }
}
