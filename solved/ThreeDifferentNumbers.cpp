#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>

using namespace std;

long long unsigned int a[3];

void arrange(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i] < a[j]){
                long long unsigned int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void print(){
    for(int i = 0 ; i < 3; i++)
        printf("%llu ", a[i]);
    printf("\n");
}

long long unsigned int MOD = 1000000007;

void solve(){
    long long unsigned int ans = 1;
    for(int i = 0; i < 3; i++){
        ans = ((ans % MOD) * ((a[i] - i) % MOD)) % MOD;
    }
    printf("%llu\n", ans);
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    while (t--){
        for(int i = 0; i < 3; i++){
            scanf("%llu", a + i);
        }
        arrange();
     //   print();
        solve();
    }
    
    
}