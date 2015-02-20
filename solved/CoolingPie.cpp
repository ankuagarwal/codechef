#include<stdio.h>

main(){
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        int pieorder[101];
        int selforder[101];
        for( int i = 1; i < 101; i++){
            pieorder[i] = 0;
            selforder[i] = 0;
        }
        int n;
        scanf("%d", &n);
        int a;
        for( int i = 0; i < n; i++){
            scanf("%d", &a);
            pieorder[a]++;
        }
        for( int i = 0; i < n; i++){
            scanf("%d", &a);
            selforder[a]++;
        }

        int next =0;
        int count = 0;

        for( int i = 1; i < 101; i++){
            if ( pieorder[i] == 0 ) continue;
            pieorder[i]--;
            if ( next <= i )
                    next = i;
            int j = next;
            for( j ; j < 101; j++){
                    if(selforder[j] == 0) continue;
                    selforder[j]--;
                    next = j;
                    count++;
                    break;
            }
            if(j >=101) break;
            if(pieorder[i] != 0) i--;
        }
        printf("%d\n", count);
    }
}
