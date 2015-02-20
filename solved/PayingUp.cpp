#include<stdio.h>

int checkSum ( int cost[], int m, int end){
    if(m == 0) return 1;
    int flag = 0;
    for( int i = end; i >= 1; i--){
        if( cost[i] != 0 && m - i >= 0){
            cost[i] = cost[i] - 1;
            if(checkSum( cost, (m - i), i) == 1){
                flag =1;
                break;
            }
            cost[i]++;
        }
    }
    if( flag == 0) return 0;
    else return 1;

}

main(){
   freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while ( t--){
        int m, n;
        scanf("%d", &n);
        scanf("%d", &m);
        int a;
        int * cost = new int [1001];
        for( int i = 0; i < 1001; i++ )
                cost[i] = 0;
        for( int i = 0; i < n; i++ ){
                scanf("%d", &a);
                cost[a] = cost[a] + 1;
        }
        if(checkSum(cost, m, 1000) == 0)
                printf("No\n");
         else
                printf("Yes\n");
    }
}
