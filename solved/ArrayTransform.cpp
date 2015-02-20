#include<stdlib.h>
#include<stdio.h>

main(){

    int t;
    scanf("%d", &t);
    int n, k;
    while( t--){
        scanf("%d %d", &n, &k);
        k = k+1;
        int x;
        int rem1 = -1;
        int count1 = 1;
        int count2 = 0;
        int rem2 = -1;
        scanf("%d", &x);
        rem1 = x % k;
        for( int i = 2; i <= n; i++){
            scanf("%d", &x);
            if( (x% k) == rem1){
                    count1++;
            }
            else if( (x%k) == rem2){
                     count2++;
            }else if( rem2 == -1){
                    rem2 = x%k;
                    count2 = 1;
            }
        }
        if( ((count1+ count2) == n) && ((count1<=1) || (count2<=1)))
                printf("YES\n");
        else printf("NO\n");

    }
}
