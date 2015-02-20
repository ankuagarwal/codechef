#include<stdio.h>

main(){
    int n;
    scanf("%d", &n);
    while (n != 0){
        int * a = new int[n+1];
        int * b = new int[n+1];
        for (  int i = 1; i <= n; i++ ){
            scanf("%d", a+i);
            b[a[i]] = i;
        }
        int flag = 0;
        for( int i = 1; i <= n; i++){
            if(a[i] != b[i]){
                    flag = 1;
                    break;
            }
        }
        if( flag == 1)
                    printf("not ambiguous");
        else
                    printf("ambiguous");
        printf("\n");
        scanf("%d", &n);
    }
}
