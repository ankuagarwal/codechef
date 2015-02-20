#include<iostream>
#include<stdio.h>
#include<math.h>

main(){
    long n, k;
    scanf("%d%d",&n, &k);
    long number;
    long count = 0;
    for(long i = 0 ; i < n; i ++){
        scanf("%d",&number);
        if(number % k == 0)
            count ++;
    }
    printf("%d",count);
}
