#include<stdio.h>
#include<math.h>

long calculateRemainder ( long dummy, long div){
    if( div == 1 ) return  dummy % 10000;

    if( div % 2 == 0){
            long rem = calculateRemainder( dummy, div/2);
            long x = ((rem % 10000) * (rem % 10000)) % 10000;
            return x;
    }
    else{
            long rem = calculateRemainder( dummy, div -1);
            long x = ((dummy % 10000) * (rem % 10000)) % 10000;
            return x;
    }
}
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

    int * checksq = new int[500001];
    int * sqrtnm = new int [500001];
    for( int i = 0; i <= 500000; i ++ ){
            checksq[i] = 0;
            sqrtnm[i] = 0;
    }
    for( int i = 4; i <= 499849; i++ ){
        long y = sqrt(i);
        if( pow(y, 2) == i){
                sqrtnm[i] = y;
                checksq[i] = 1;
        }
    }

    long t;
    scanf ( "%d", &t );
    while ( t-- ){
        long a;
        scanf ( "%d", &a );
        if ( a == 1) {
                printf ( "%c\n", '1');
                continue;
        }
        if( check[a -1] == 0 ){
                printf("%c\n", '1');
                continue;
        }
        long dummy = a;
        long primec = 0;
        long totaldiv = 1;
        for (  long i = 0 ; i < x ; i ++){
            totaldiv = totaldiv * (primec +1);
            primec = 0;
            if (dummy == 1) break;
            if( check[ dummy -1 ] == 0){
                totaldiv = totaldiv * 2 ;
                break;
            }
            while ( dummy > 0){
                if( dummy % finalprime[i] == 0){
                        primec++;
                        dummy = dummy / finalprime[i];
                }
                else break;
            }
        }
        if( checksq[a] == 1){
                dummy = sqrtnm[a];
                totaldiv = totaldiv -2;
        }
        else{
                dummy = a;
                totaldiv = (totaldiv - 2)/2;
        }
        int extension = 0;
        if ((totaldiv * log (dummy)) >= log(10000))
                extension = 1;
        long rem = calculateRemainder(dummy, totaldiv);
        if( extension == 1){
                int remainlen =0;
                if(rem ==0)
                        remainlen = 3;
                else{
                        int len = log10(rem) +1;
                        remainlen = 4 - len;
                }
                for( int i = 1; i <= remainlen; i++)
                        printf("%c", '0');
        }
        printf("%d\n",rem);
    }
}
