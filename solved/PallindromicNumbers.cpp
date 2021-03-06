#include<stdio.h>
#include<string.h>
#include<math.h>

int a[1000000];

int checkForPallindrom(int count){
    int limit = count/2;
    for( int i = 0; i < limit; i++){
        if(a[i] != a[count-i-1])
            return 0;
    }
    return 1;
}

main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while( t--){
        long long int n;
        scanf("%lld", &n);

        if( n == 1) {
            printf("%c\n", '2');
            continue;
        }
        if( n == 2) {
            printf("%c\n", '3');
            continue;
        }
          if( n == 3) {
            printf("%c\n", '2');
            continue;
        }

        long long int limit = sqrt(n);
        int result = 0;
        for(long long int base = 2; base <= limit; base++){
            long long int dummy = n;
            int count = 0;
            while( dummy != 0){
                a[count] = dummy % base;
                dummy = dummy/ base;
                count++;
            }
            if(checkForPallindrom(count) == 1){
                    result = 1;
                    printf("%d\n", base);
                    break;
            }
        }
        if(result == 1) continue;
        for( long long int i = limit; i >= 2; i--){
            if(( n%i == 0) &&  (i < (n/i -1))){
                      result = 1;
                     printf("%lld\n", (n/i -1));
                    break;
            }
        }
        if( result == 0)
            printf("%lld\n", n-1);
        }
    }

