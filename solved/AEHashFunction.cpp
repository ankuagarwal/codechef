#include<stdio.h>
#include<string.h>

long long unsigned int matrix[51][51][153];

void permutation(int i, int j){
    int mid = (i+j)/2;
    for( int k = 0; k <= mid; k++){
        if( (mid-k) < 0 || (i-k) <0 || (j-mid+k) < 0)
                continue;
        if(k > i || (mid-k) > j || (i-k) > i || (j-mid+k) >j) continue;
        for(int a = 0; a < 153; a++){
                if(matrix[k][mid-k][a] == 0)  continue;
                for( int b = 0; b < 153; b++){
                        if(matrix[i-k][j-mid+k][b] == 0)  continue;
                        long long unsigned int mul = (matrix[k][mid-k][a] * matrix[i-k][j-mid+k][b]) ;
                        long long unsigned int m = mul % 1000000007;
                        if( a >= b)
                                matrix[i][j][i+a] = (matrix[i][j][i+a] + m) % 1000000007;
                        else
                                matrix[i][j][i+b] = (matrix[i][j][i+b] + m) % 1000000007;
                }
        }
    }
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for ( int i = 0; i < 51; i++){
        for ( int j = 0; j < 51; j++){
                for ( int k = 0; k < 153; k++)
                    matrix[i][j][k] = 0;
        }
    }

    matrix[1][0][1] = 1;
    matrix[0][0][0] = 1;

    for( int i = 1; i < 51; i++)
        matrix[0][i][0] = 1;

    for(int i = 2; i < 51; i++){
        int mid = i /2;
        if( i% 2 != 0) mid++;
        int j;
        for(  j = 0; j < 153; j++){
            if(matrix[mid][0][j] != 0)
                break;
        }
        matrix[i][0][i+j] = 1;
    }

    for ( int i = 1; i < 51; i++){
        for ( int j = 1; j < 51; j++){
            permutation(i, j);
        }
    }

    int t;
    scanf("%d", &t);
    while( t--){
            int a, e, v;
            scanf("%d", &a);
            scanf("%d", &e);
            scanf("%d", &v);
            long long unsigned int ans = matrix[a][e][v];
            printf("%llu\n", ans);
    }
}
