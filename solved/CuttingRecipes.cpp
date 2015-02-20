#include<stdio.h>

int gcd(int a, int b){
        if ( b == 0) return a;
        else return gcd ( b, a%b );
}

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[50];
        int x;
        scanf("%d", &x);
        a[0]= x;
        int g = gcd(x,x);
        for( int i = 1; i < n ; i++){
            scanf("%d", a+i);
            g= gcd(g, a[i]);
        }
        for(int i = 0; i < n ; i++)
            printf("%d ", a[i]/g);
        printf("\n");
    }
}
