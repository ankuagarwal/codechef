#include<stdio.h>
#include<string.h>

long t;
long * ans = new long [10000000];

long multiple (long n, long count){
        long c =0;
        long carry = 0;
        for( long j = 0 ; j < count; j++ ){
                long mul = ans[j] * n + carry;
                ans[c] = mul % 10;
                carry = mul / 10;
                c++;
        }
        if( carry != 0){
                while(carry != 0){
                        ans[c] = carry % 10;
                        carry = carry / 10;
                        c++;
                    }
        }
        return c;
}

long factorial ( long a, long count){
        for( long j = a ; j > 1; j --)
                count = multiple ( j , count);
        return count;
}

main(){
    scanf("%d", &t);
    while( t--){
            long  a;
            scanf("%d", &a);
            ans[0] = 1;
            long count = 1;
            if( a != 1 && a != 0)
                    count = factorial (a, count);
            for(long j = (count-1); j >= 0; j --)
                    printf("%d", ans[j]);
            printf("\n");
    }
}
