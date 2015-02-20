#include<stdio.h>

main(){
    int* arr = new int[1000001];
    for( int i = 0 ; i < 1000001; i++)
        arr[i] = 0;
    int n;
    scanf("%d",&n);
    while( n--){
        int a;
        scanf("%d", &a);
        arr[a] = arr[a] + 1;
    }
    for( int i = 0; i < 1000001; i++)
        if( arr[i] > 0){
            for (  int j = 0; j < arr[i]; j++)
                printf("%d\n", i);
        }
}
