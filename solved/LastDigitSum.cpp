#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long signed int function(long long signed int a){
   long long signed int sum = 0;
   long long signed int dummy = a;
    while( dummy >0){
        long long signed int rem = dummy % 10;
        if( (rem %2) == 0)
                sum = sum + (2* rem);
        else
                sum = sum + rem;
        dummy = dummy/10;
    }
     sum = sum%10;
    return sum;
}

main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

      int t;
      scanf("%d", &t);
      while( t--){
                long long signed int a;
                long long signed b;
                scanf("%lli", &a);
                scanf("%lli", &b);
                long long signed int sum = 0;

                long long signed int nearA = a + (10 - (a%10));
                long long signed int nearB =  b - (b%10);

                long long signed int c = nearB-nearA;
                if( c < 0){
                           sum = 0;
                           for( long long signed int i = a;  i <=b; i++)
                                     sum = sum + function(i);
                }
                else{
                           c = c /10;
                           sum = c * 45;
                           for( long long signed int i = a; i < nearA; i++)
                                    sum = sum + function(i);
                           for( long long signed int i = nearB; i <= b; i++)
                                    sum = sum + function(i);
                }


                printf("%lli\n", sum);
      }
}
