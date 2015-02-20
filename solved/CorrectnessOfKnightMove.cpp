#include<stdio.h>
#include<string.h>

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char a[100];
    int t;
    scanf("%d", &t);
    getchar();

    while( t--){
        gets(a);
        int len = strlen(a);
        if(len == 5 && ('a' <= a[0] && a[0] <='h') && ('1' <= a[1] && a[1] <= '8') && (a[2] == '-') && ('a' <= a[3] && a[3] <='h') && ('1' <= a[4] && a[4] <= '8')){
            if(a[0]+2 == a[3] && (a[1]+1 == a[4] || a[1]-1 == a[4])) printf("Yes\n");
            else if(a[0]-2 == a[3] && (a[1]+1 == a[4] || a[1]-1 == a[4])) printf("Yes\n");
            else if((a[0]+1 == a[3] || a[0]-1 == a[3]) && a[1]+2 == a[4]) printf("Yes\n");
            else if((a[0]+1 == a[3] || a[0]-1 == a[3]) && a[1]-2 == a[4]) printf("Yes\n");
            else printf("No\n");
        }
        else printf("Error\n");
    }
}
