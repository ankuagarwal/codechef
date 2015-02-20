#include<stdio.h>

int change(int winner){
    if( winner == 1)
        return 2;
    else return 1;
}

main(){
    int t;
    scanf("%d", &t);
    while ( t--){
        int n;
        scanf("%d", &n);
        int * pile = new int[n+1];
        for( int i = 1 ; i <= n; i++)
            scanf( "%d", pile + i );
        int winner =1;
        for( int i = 1; i <= n; ){
            if( pile[i] >= i){
                pile[i] = pile[i]-i;
                winner = change(winner);
            }
            else i = i + 1;
        }
        if( pile[n] < n)
            winner = change(winner);

        if( winner == 1)
                printf("ALICE\n");
        else    printf("BOB\n");
    }
}
