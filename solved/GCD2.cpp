#include<stdio.h>
#include<string.h>
#include<math.h>

long remain ( long a, char b[], int bl ) {
        long r = 0;
        long d = a;
        r = (b[0] - '0') % a;
        for( int i = 1; i < bl; i++ )
                r = ( r * 10 + (b[i] - '0')) % a;
        return r;
}
long gcd ( long a, long b ) {
        if ( b == 0) return a;
        else return gcd ( b, a%b );
}

main(){
        int t;
        scanf("%d", &t);
        while(t--){
                long a;
                char* bchar = new char [260];
                scanf ( "%d", &a);
                scanf ( "%s", bchar);
                int bl = strlen ( bchar);
                char *ans = new char [270];
                if ( a == 1 )
                        ans[0] = 1 + '0';
                if( a == 0)
                        for ( int j = 0; j < bl; j ++ )
                                ans[j] = bchar[j] ;
                else{
                        long g = gcd ( a, remain (a, bchar, bl));
                        int digit = log10(g);
                        long power = pow(10,digit);
                        int count = 0;
                        while(power != 0){
                                ans[count] = (g / power) + '0';
                                g = g % power;
                                count ++;
                                power = power / 10;
                        }
                }
                printf ("%s\n", ans);
            }
}
