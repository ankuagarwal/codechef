#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int matrix[21][201][10];

int function( int n, int w, int a){
    if( n == 0) {
        if( w == 0) return 1;
        else return 0;
    }
    if( matrix[n][w][a] != -1)
        return matrix[n][w][a];
    int count = 0;
    for( int i = 0; i < 10; i++)
        count = (count + function(n-1, w-abs(i-a), i)) % 1000007;
    matrix[n][w][a] = count;
    return count;
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

        for( int i = 1; i < 21; i++){
            for( int j = 0; j < 201; j++){
                for( int k = 0; k <10; k++)
                    matrix[i][j][k] = -1;
            }
        }

        int t;
        scanf("%d", &t);
        while( t--){
            int n, weight;
            scanf("%d %d", &n, &weight);
            int count = 0;
            for( int i = 1; i <= 9; i++){
                count = (count + function(n-1, weight, i )) % 1000007;
            }
            printf("%d\n", count);
        }
}
