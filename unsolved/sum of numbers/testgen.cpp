#include<stdio.h>

main(){
    freopen("input.txt", "w", stdout);
    int t = 100;
    printf("%d\n", t);
    while ( t--){
        for ( int i = 0; i < 20000; i++)
            printf("%c", '7');
         printf("\n");
    }
}
