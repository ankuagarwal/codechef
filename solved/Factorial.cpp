#include<stdio.h>
#include<string.h>

main(){
    long t;
    scanf("%d", & t);
    long * a = new long [t];
    long * zero = new long[t];
    for ( long i = 0; i < t ; i ++ ){
        scanf("%d", a + i);
        zero[i] = 0;
        long power = 5;
        long rem = 0;
        while ( rem != a[i]){
            zero[i] = zero[i] + ( a[i] / power);
            rem = a[i] % power;
            power = power * 5;
        }
    }
    for( long i = 0; i < t; i ++ )
        printf ("%d\n", zero[i]);
}
