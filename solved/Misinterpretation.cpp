#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int arr[100001];

long long int function ( int a){
    for( int i = 1; i <= a; i++)
        arr[i] = -1;
    int count = 0;
    int mid = a/2;
    int x = 2;
    for( int i = 1; i <= mid; i++){
        arr[i] = x;
        arr[mid+i] = x-1;
        x = x+2;
    }
    if( a%2 != 0)
        arr[a] = a;

    long long int prod = 1;
    for( int i = 1; i <= a; i++){
        if( arr[i] == -1) continue;
        prod = (prod * 26)%1000000007;
        int next = arr[i];
        arr[i] = -1;
        while( next != i){
               int tempnext = arr[next];
              arr[next] = -1;
              next = tempnext;
        }
    }
    printf("%lld\n", prod);
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while( t--){
            int n;
            scanf("%d", &n);
            function(n);
        }
}
