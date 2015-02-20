#include<stdio.h>
#include<math.h>

long long int a[32768];
long double b[32768];


long long int treeproduct (int n){
    if( n == 1) {
        if(b[2] > b[3])
                a[1] = (a[1] * a[2]) % 1000000007;
        else
                a[1] = (a[1] * a[3]) % 1000000007;
        return a[1];
    }
    if(b[2*n] >= b[2*n+1]){
            a[n] = (a[n] * a[2*n]) % 1000000007;
            b[n] = b[n] * b[2*n];
    }
    else{
            a[n] = (a[n] * a[2*n+1]) % 1000000007;
            b[n] = b[n] * b[2*n+1];
    }
    return treeproduct(n-1);
}

main(){
    while(1){
        int h;
        scanf("%d", &h);
        if( h == 0) break;
        int max = pow(2, h) -1;
        for( int i = 1; i <= max; i++){
            scanf("%lld", a+i);
            b[i] = a[i];
        }
        int limit = pow(2, h-1);
        long long int ans = treeproduct(limit-1);

        printf("%lld\n", ans);
    }
}
