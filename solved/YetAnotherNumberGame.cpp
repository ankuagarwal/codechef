#include<stdio.h>

main(){
    int t;
    scanf("%d",&t);
    while ( t--){
        long a;
        scanf("%d",&a);
        if( a % 2 == 0)
            printf("ALICE\n");
        else
            printf("BOB\n");
    }
}
