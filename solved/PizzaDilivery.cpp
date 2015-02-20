#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int X[501][1001];
int H[501];
int K[501];
int n;

void print(){
    for(int i = 1 ; i <= n; i++)
        printf("%d ", H[i]);
    printf("\n");
    for(int i = 1; i <= n; i++)
        printf("%d ", K[i]);
    printf("\n");
    
}

void printX(int max){
    for(int i = 0; i <=n; i++){
        for(int j = 0; j<= max; j++)
            printf("%d ", X[i][j]);
        printf("\n");
    }
}

int min (int x, int y){
        if(x < y)
            return x;
        else
            return y;
}

void solve(){
    int maxIndex = 0;
    int maxValue = H[0];
    for(int i = 1; i <= n; i++){
        if(H[i] > maxValue){
            maxValue = H[i];
            maxIndex = i;
        }
    }
    maxValue = 2 * maxValue;
    
    X[0][0] = 0;
    for(int i = 1; i <= n; i++)
        X[i][0] = 0;
    for(int i = 1; i <= maxValue; i++)
        X[0][i] = 1000000000;
    
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= maxValue; j++){
            if(K[i] <= j)
                X[i][j] = min (X[i-1][j], 1 + X[i][j-K[i]]);
            else
                X[i][j] = X[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += X[n][2*H[i]];
    }
    printf("%d\n", ans);
}

void initialize(){
    for(int i = 0; i < 501; i ++){
        for(int j = 0; j < 1001; j++)
            X[i][j] = 0;
    }
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    while (t--){
        initialize();
        
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", H+i);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", K+i);
        }
        
       // print();
        
        solve();
        
    }
}