#include<stdio.h>
#include<stdlib.h>

int arr[100];
int dept[100];

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    while(t--){
        int a [1001];
        for( int i = 0; i < 1001; i++)
            a[i] = 0;
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        for(int i = 0; i < n; i++)
            scanf("%d", &dept[i]);


        for( int i = 0; i < n; i++){
            for( int j = arr[i]; j < dept[i]; j++){
                    a[j]++;
            }
        }
        int max = 0;
        for(int i = 0; i < 1001; i++)
            if( a[i] >= max) max = a[i];
        printf("%d\n", max);
    }
}
