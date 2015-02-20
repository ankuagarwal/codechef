#include<stdio.h>
#include<math.h>

int function( int n){
    int x = pow(2, (n-1));
    x = x % 8388608;
    int y = (((n % 8388608)  * ((n+1) % 8388608)) % 8388608 )/2;
    int z = (x * y) % 8388608;
    return z;
}

int ans[23];

main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    int sum = 0;
    int x = 0;
    for( int i = 1; i <= 22; i++){
           x =  function( i);
           sum = (sum + x) % 8388608;
           ans[i] = sum;
    }

    int t;
    scanf("%d", &t);
    while( t--){
        int n;
        scanf("%d", &n);
        if( n >= 22)
                printf("%d\n", ans[22]);
        else
                printf("%d\n", ans[n]);
    }
}
