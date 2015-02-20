#include<stdio.h>
#include<string.h>

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char a[100];
        scanf("%s", a);
        int len = strlen(a);
        int count = 0;
        for(int i = 0; i <len; i++){
            if(a[i] == 'A' || a[i] == 'D' || a[i] == 'O' || a[i] == 'P' || a[i] == 'Q' || a[i] == 'R') count++;
            else if( a[i] == 'B') count = count + 2;
        }
        printf("%d\n", count);
    }
}
