#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long unsigned int total( long long unsigned int totalPages, long long unsigned int sumNonPrinted){
        long long unsigned int sum = (totalPages * (totalPages + 1))/2;
        return (sum-sumNonPrinted);
}

main(){
    freopen("input.txt", "r", stdin);
    freopen( "output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--){
        long long unsigned int totalPages;
        long long unsigned int nonPrinted;
        long long unsigned int toredPages;
        long long unsigned int sumNonPrinted  = 0;

        scanf("%lld", &totalPages);
        scanf("%lld", &nonPrinted);

        long long unsigned int x;
        for( long long unsigned int i = 0; i < nonPrinted; i++){
                scanf("%lld", &x);
                sumNonPrinted += x;
        }
        scanf("%lld", &toredPages);

        long long unsigned int totalSum = total( totalPages, sumNonPrinted);

        if(totalPages % 2 != 0) totalPages++;
        long double ans =((long double) (totalSum * ((totalPages/2) - toredPages)))/(totalPages/2);

        printf("%.4llf\n", ans);
    }
}
