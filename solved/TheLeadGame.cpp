#include<stdio.h>

main(){
    long n;
    scanf ( "%d", &n );
    long totalplayer1 = 0;
    long totalplayer2 =0;
    long player1 = 0;
    long player2 =0;
    int winner = 0;
    int lead = 0;
    for( long i = 1; i <= n ; i++ ){
        scanf ( "%d", &player1 );
        scanf ( "%d", &player2 );
        int dummylead = 0;
        int dummywinner = 0;
        totalplayer1 = totalplayer1 + player1;
        totalplayer2 = totalplayer2 + player2;
        if ( totalplayer1 > totalplayer2 ){
            dummylead = totalplayer1 - totalplayer2;
            dummywinner = 1;
        }
        else {
            dummylead = totalplayer2 - totalplayer1;
            dummywinner = 2;
        }
        if( dummylead > lead ){
            lead = dummylead;
            winner = dummywinner;
        }

    }
    printf("%d %d", winner, lead);
  //  printf("%d", lead);
}
