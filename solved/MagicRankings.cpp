#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int X[101][101];
int Y[101][101];
int n;


void printX(){
    for(int i = 1; i <= n; i++){
        for( int j = 1; j <= n; j++){
            printf("%d ", X[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void printY(){
    for(int i = 1; i <= n; i++){
        for( int j = 1; j <= n; j++){
            printf("%d ", Y[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int max (int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

void solve(){
    Y[n][n] = 0;
    for(int i = n-1; i >= 1; i--){
        Y[i][n] = Y[i+1][n] + X[i][n];
        Y[n][i] = Y[n][i+1] + X[n][i];
    }
    for(int i = n-1; i >= 1; i --){
        for( int j = n-1; j >= 1; j--){
            Y[i][j] = max(Y[i+1][j], Y[i][j+1]) + X[i][j];
        }
    }
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
   
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int y;
                scanf("%d", &y);
                X[i][j] = y;
            }
        }
        solve();
        
        if(Y[1][1] < 0){
            printf("Bad Judges\n");
            
        }
        else {
            float ans = (float) Y[1][1]/(2*n -3);
            printf("%f\n", ans);
        
        }
    }
}
