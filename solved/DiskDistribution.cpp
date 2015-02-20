#include<cstdio>
#include<cstdlib>
#include<cmath>

main(){
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while( t--){
        int n, m;
        scanf("%d %d", &n, &m);

        int result[n+1];
        int tempresult[n+1];
        for( int i = 0; i <= n; i++){
            result[i] = 0;
            tempresult[i] = 0;
        }
        int a[n+1];

        int decpower = 0;
        int x, y;
        scanf("%d %d", &x, &y);
        decpower += x;
        int limit = y-x;
        if( limit <= n){
            for( int i = 0; i <=limit; i++)
                result[i] = 1;
        }
        else{
            for( int i = 0; i <=n; i++)
                result[i] = 1;
        }

        for( int i = 1; i < m; i++){
                scanf("%d %d", &x, &y);
                decpower += x;
                limit = y-x;

               for( int j = 0; j <=n; j++){
                        tempresult[j] = result[j];
                        result[j] =0;
               }

               int d = limit;
               if( limit > n) d = n;
               for( int j = 0; j <=n; j++){
                        for( int k = 0; k <= d; k++){
                                  if( (j+k) <= n){
                                        result[j+k] = (result[j+k] + tempresult[j] ) %1000000007;
                                  }

                        }
                }
        }
        if( (n-decpower) >= 0)
                printf("%d\n", result[n-decpower]);
        else
                printf("%d\n", 0);

        }
}
