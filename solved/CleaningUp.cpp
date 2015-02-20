#include<stdio.h>

main(){
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while( t--){
        int jobs[1001];
        for( int i = 0; i< 1001; i++)
            jobs[i] = 0;
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int a;
        for( int i = 0; i < m; i++){
            scanf("%d", &a);
            jobs[a] = 1;
        }
        int chef[1001];
        int assist[1001];
        int flag = 0;
        int countchef = 0;
        int countassist = 0;
        for( int i = 1; i <= n; i++){
            if(jobs[i] == 0){
                    if (flag ==0){
                            chef[countchef] = i;
                            countchef++;
                            flag = 1;
                    }
                    else {
                            assist[countassist] = i;
                            countassist++;
                            flag = 0;
                    }
            }
        }
        for( int i = 0; i < countchef; i++)
            printf("%d ", chef[i]);
        printf("\n");
        for( int i = 0; i < countassist; i++)
            printf("%d ", assist[i]);
        printf("\n");
    }
}
