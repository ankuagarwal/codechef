#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

char n[1000001];

void initialize(){
    int numerator = 103993;
    int denominator = 33102;
    int remainder = 0;
    int quoitent = 0;
    
    for(int i = 0; i <= 1000000; i++){
        if(numerator < denominator){
            n[i] = '0';
            numerator = numerator * 10;
            continue;
        }
        quoitent = numerator/denominator;
        remainder = numerator - quoitent * denominator;
        numerator = remainder * 10;
        n[i] = '0' + quoitent;
    }
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    initialize();
    
    int t;
    scanf("%d", &t);
    while (t--){
        int x;
        scanf("%d", &x);
        
        printf("%c", n[0]);
        
        if(x != 0){
            printf(".");
            for(int i = 1; i <= x; i++)
                printf("%c", n[i]);
         }
         printf("\n");
    }
}
