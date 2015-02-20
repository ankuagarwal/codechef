#include<stdio.h>


long long unsigned int gcd ( long long unsigned int a, long long unsigned int b ) {
        if ( b == 0) return a;
        else return gcd ( b, a%b );
}

long long unsigned int callingFact( long a,  long b){
    long *check = new long [b+1];
    for( long i = 0 ; i< b+1; i++)
            check[i] = 1;
    long long unsigned int ans = 1;
    for ( long i = b; i >=1; i--){
            long x = a - i+ 1;
            long g1 = gcd (x, i);
            long y = x/ g1;
            long z = i / g1;
            long g2 = gcd ( ans , z);
            ans = (ans/ g2) * y ;
            check[i] = z /g2;
    }
    for ( long i = b; i >=1; i--)
                ans = ans / check[i];

    return ans;
}


main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--){
            long n;
            long k;
            scanf("%d", &n);
            scanf("%d", &k);
            if( n == k){
                printf("1\n");
                continue;
            }
            if( ((n-k) == 1) || (( k-1 ) == 1)){
                printf("%d\n", n-1);
                continue;
            }
            long limit = 0;
            if( ( n-k ) < ( k-1 ) )
                limit = n-k;
            else
                limit = k-1;

          printf("%llu\n", callingFact ( n-1, limit ));
    }
}
