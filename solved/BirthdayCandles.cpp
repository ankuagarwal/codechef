#include<stdio.h>
#include<math.h>

main(){
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);

    while(t--){
        int * order = new int [9];
        for( int i = 0; i < 9 ; i++)
                order[i] = -1;
        int x;
        for( int i = 0; i < 10; i++){
            scanf("%d", &x);
            if(order[x] == -1)
                    order[x] = i;
            if( order[x] == 0)
                        order[x] = i;
        }
        for( int i = 0; i < 9; i++){
            if(order[i] != -1){
                if(order[i] != 0)
                    for( int j = 0; j < (i+1); j++)
                        printf("%d", order[i]);
                else{
                    printf("%c", '1');
                    for( int j = 0; j < (i+1); j++)
                        printf("%d", order[i]);
                }
                break;
            }
        }
        printf("\n");
    }
}
