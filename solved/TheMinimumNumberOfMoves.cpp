#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>

using namespace std;

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        int min = 10001;
        int sum = 0;
        int x ;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            sum = sum + x;
            if(x < min)
                min = x;
        }
        int ans = sum - n * min;
        printf("%d\n", ans);
        
    }
    
}
