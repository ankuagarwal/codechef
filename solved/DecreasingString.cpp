#include<stdio.h>
#include<string.h>

main(){
    char a[] = "zyxwvutsrqponmlkjihgfedcba";
    int len = strlen(a);
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);
        int prefix = k % 25;
        if(prefix != 0)
            printf("%s", &a[len-prefix-1]);
        int suffix = k/25;
        for(int i = 1; i <= suffix; i++)
                printf("%s", a);
       printf("\n");
    }
}
