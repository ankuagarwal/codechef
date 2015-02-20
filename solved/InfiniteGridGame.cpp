#include<stdio.h>

// Alice 1 Bob 0
int arr[1001][1001];
main(){
    freopen( "input.txt", "r", stdin);
    freopen( "output.txt", "w", stdout);

    for( int i = 0; i < 1001; i++)
        for( int j = 0; j < 1001; j++)
            arr[i][j] = 0;

    int i = 0;
    int j = 0;
    while( i < 1001 && j < 1001){
        if( arr[i][j] == 0){
            for( int x = j+ 1; x < 1001; x++){
                arr[i][x] = 1;
                arr[x][i] = 1;
            }
            for( int y = i+ 1; y < 1001; y++){
                arr[y][j] = 1;
                arr[j][y] = 1;
            }
            int x = i +1;
            int y = j+1;
            for( ; x < 1001 && y < 1001;){
                arr[x][y] = 1;
                arr[y][x] = 1;
                x++;
                y++;
            }
            i = i +1;
            j = j+2;
        }
        else{
            i = i +1;
            j = j+1;
        }
    }

    int t;
    scanf("%d", &t);
    while( t--){
        int m, n, p , q;
        scanf("%d %d %d %d", &m, &n, &p, &q);
        if( arr[m-p][n-q] == 0)
                printf("%s\n", "Bob");
        else
                printf("%s\n", "Alice");
    }
}
