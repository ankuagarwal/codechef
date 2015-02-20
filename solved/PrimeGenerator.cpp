#include<stdio.h>
#include<string.h>
#include<math.h>

main(){
//    freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int * prime = new int [31623];
    int * primenumber = new int [3402];
    long count = 0;
    for( long i = 2 ; i < 31623; i++ ){
        if( prime[i] == 1)
            continue;
        prime[i] = -1;
        primenumber[count] = i;
        count++;
        for( long j = i + i ; j < 31623; j = j + i )
               prime[j] = 1;
    }

    int t;
    scanf("%d", &t);
    while( t--) {
        long m;
        long n;
        scanf ( "%d", &m);
        scanf( "%d", &n);
        long diff = n - m + 1;
        int * check = new int [diff];
        int xyz = 0;
        long p = sqrt(n);
        for ( long k = 0; k < count; k++  ){
                if( primenumber[k] >= p) break;
                long start = 0;
                if ( primenumber[k] >= m){
                    xyz++;
                        printf("%d\n",  primenumber[k] );
                        start = primenumber[k] - m;
                }
                else{
                        long rem = m % primenumber[k];
                        if( rem != 0)
                            start = primenumber[k] - ( m % primenumber[k] );
                }
                for ( long j = start ; j < diff; j = j + primenumber[k])
                            check[j] = 1;
            }


        long i = 0;
        if( m == 1) i ++;
        for( i ; i < diff; i ++){
            if( check[i] == 0){
                printf("%d\n", (i+m));
                xyz++;
            }
        }
        printf("\n");
        printf("%d\n", xyz);
    }
}
