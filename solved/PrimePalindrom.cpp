#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int testForPrime(int x){
        int m = sqrt (x);
        int i = 1;
        int y = 6 *i;
        for( i ; y+1 <= m ; i++){
            if( x % (y+1) == 0 || x % (y-1) == 0)
                return 0;
            y = y + 6;
        }
        return 1;
}

int testForPalindrom(int x){
    int rev = 0;
    int dummy = x;
    while (dummy > 0){
        rev = rev *10 + dummy % 10;
        dummy = dummy / 10 ;
    }
    if(x == rev)
       return testForPrime(x);
    else return -1;
}

main(){
        long x;
        scanf("%d",&x);

        for(long i = x; i <=1000000000; i ++){
            if( i % 2 == 0 || i % 3 == 0)
                continue;
            if( (i -1) % 6 != 0 && (i+1) % 6 != 0)
                continue;
            if( testForPalindrom(i) == 1) {
                printf("%d",i);
                break;
           }

        }

}
