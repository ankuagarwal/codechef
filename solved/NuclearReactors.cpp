#include<stdio.h>
#include<math.h>

main(){
    long long unsigned int a;
    int n, k;
    scanf("%llu", &a);
    scanf("%d", &n);
    scanf("%d", &k);
    if(a !=0 && n != 0){
        int * arr = new int[k];
        for( int i = 0; i< k ; i++)
            arr[i] = 0;
        int nprime = n+1;
        int digit = (log10(a)/ log10(nprime));

        int max = pow(nprime, digit);
        while (max > 0){
            int x = a/ max;
            arr[digit] = x;
            a= a%max;
            max = max/ nprime;
            digit--;
        }
        for( int i = 0; i< (k-1); i++){
            printf("%d", arr[i]);
            printf(" ");
        }
        printf("%d\n", arr[k-1]);
    }
    else{
        for( int i = 0; i< (k-1); i++){
            printf("%c", '0');
            printf(" ");
        }
        printf("%c\n", '0');
    }
}
