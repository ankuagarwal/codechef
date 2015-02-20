#include<stdio.h>

main(){
    int n;
    scanf("%d", &n);
    int position;
    int mess = 0;
    for( long i = 1 ; i <= n; i++){
        scanf("%d", &position);
        int x = position - i;
        if( x == 0) continue;
        if( x < 0)   x = 0 - x;
        if( x >= (n- x))
            mess = mess + n-x;
        else
            mess = mess + x;
    }
    printf("%d", mess);
}
