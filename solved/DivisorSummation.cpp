#include<stdio.h>
#include<math.h>


main(){
   freopen ( "input.txt", "r", stdin );
    freopen ( "output.txt", "w", stdout );

    int * prime = new int [708];
    long * primenumber = new long [126];
    long count = 0;
    for( int i = 2 ; i < 708; i++ ){
        if( prime[i] == 1)
            continue;
        primenumber[count] = (long) i;
        count ++;
        for( int j = i + i ; j < 708; j = j + i )
               prime[j] = 1;
    }

    int * check = new int [500000];
    long p = sqrt(500000);
    long * finalprime = new long[41538];
    long x = 0;
    for ( long k = 0; k < count; k++  ){
        if( primenumber[k] >= p)
                break;
        long start = 0;
        start = 2 * primenumber[k] - 1;

        for ( long j = start ; j < 500000; j = j + primenumber[k])
                check[j] = 1;
    }

    for( long i = 1 ; i < 500000; i ++){
        if( check[i] == 0){
                finalprime[x] = i + 1;
                x++;
        }
    }


    long t;
    scanf ( "%d", &t );
    while ( t-- ){
        long a;
        scanf ( "%d", &a );

        if ( a == 1) {
                printf ( "%c\n", '0');
                continue;
        }

        if( check[a -1] == 0 ){
                printf("%c\n", '1');
                continue;
        }

        long dummy = a;
        long prod = 1;
        long sum = 1;
        long primec = 0;

        for (  long i = 0 ; i < x ; i ++){
            prod = prod * sum;
            sum = 1;
            primec = 0;
            if (dummy == 1) break;
            if( check[ dummy -1 ] == 0){
                prod = prod * ( 1 + dummy);
                break;
            }
            while ( dummy > 0){
                if( dummy % finalprime[i] == 0){
                        primec++;
                        sum = sum + pow(finalprime[i],primec);
                        dummy = dummy / finalprime[i];
                }
                else break;
            }
        }
        printf("%d\n", (prod- a));
   }
}
