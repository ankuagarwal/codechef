#include <stdio.h>

int calculateSum(int a[], int best[], int num, int row ){
    if ( row == 1){
        return (best[0] + a[0]);
    }
    int tn = row * ( row - 1)/ 2;
    int *newbest = new int[ row -1];
    for ( int i = 0 ; i < (row -1) ; i++){
        if( (a[tn + i] + best[i]) >= (a[tn + i + 1] + best[i+1]))
            newbest[i] = a[tn + i] + best[i];
        else
            newbest[i] = a[tn + i +1] + best[i+1];
    }
    int sum =  calculateSum(a,newbest, num, row-1);
    return sum;
}

main(){
    int t;
    scanf("%d", &t);
    while ( t -- ){
        int row;
        scanf("%d", &row);
        int num = row*( row + 1)/ 2;
        int *a = new int [num];
        for( int i = 0 ;i < num; i++ )
                scanf("%d", a+i);
        int *sum =  new int[(row*(row+1)/2)];
        sum[0] = calculateSum(a, sum, num, row);
        printf("%d\n", sum[0]);
    }
}
