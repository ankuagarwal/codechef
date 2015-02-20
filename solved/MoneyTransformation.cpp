#include<stdio.h>

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int olda = a;
        int oldb = b;
        int maxa = a;
        int maxb = b;
        int totalCount = 0;
        int maxCount = 0;
        while(a >= 0 ){
            if( b < c){
                if(a > 0){
                    a = a-1;
                    b = b+100;
                }
                else break;
            }
            int temp = a;
            a = b-c;
            b = temp;
            totalCount++;
            if( maxa < a){
                maxa = a;
                maxb = b;
                maxCount = 0;
            }
            else if ( maxa == a){
                    if(maxb < b){
                        maxb = b;
                        maxCount = 0;
                    }
                    else maxCount++;
            }
            else maxCount++;
            if(olda == a && oldb == b) break;
        }
        printf("%d\n", totalCount-maxCount);
    }
}
