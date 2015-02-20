#include<stdio.h>

main(){
    int t;
    scanf("%d", &t);
    while ( t--){
        long long arr[1000000];
        long long k;
        scanf("%lld",&k);
        for( long long i = 0; i < k ; i++)
            scanf("%lld", arr+i);
        int flag = 0;
        long long next =0;
        if( arr[0] == 1 && k == 1){
            printf("%s\n", "Yes");
            continue;
        }
        if(arr[0] >= 1 && k > 1){
            printf("%s\n","No");
            continue;
        }
        for( long long i = k-1; i > 0; i--){
            if(((arr[i] + next) % 2) != 0){
                    flag = 1;
                    break;
            }
            next = (arr[i] +next)/2;
        }
        if( flag == 1) printf("%s\n", "No");
        else {
            if( arr[0] == 0 && next == 1)
                printf("%s\n", "Yes");
            else printf("%s\n", "No");
        }
    }
}
