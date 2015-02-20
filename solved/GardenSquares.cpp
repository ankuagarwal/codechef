#include<stdio.h>
#include<stdlib.h>

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while( t--){
        int n, m;
        scanf("%d %d", &n, &m);
        char matrix[n][m];
        for( int i = 0; i < n; i++)
            scanf("%s", &matrix[i]);

        int count = 0;
        for( int i = 0; i< n; i++){
            for ( int j = 0; j< m; j++){
                    for( int k = 1; k < m ; k++){
                        if( ((i+ k) >= n) || ((j+k) >= m) ) continue;
                        if( matrix[i][j] != matrix[i+k][j]) continue;
                        if( matrix[i][j] != matrix[i][j+k]) continue;
                        if( matrix[i][j] != matrix[i+k][j+k]) continue;
                        if( matrix[i][j+k] != matrix[i+k][j+k]) continue;
                        if( matrix[i][j+k] != matrix[i+k][j]) continue;
                        if( matrix[i+k][j] != matrix[i+k][j+k]) continue;
                        else count++;

                    }
            }
        }
        printf("%d\n", count);
    }
}
