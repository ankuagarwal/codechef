#include<stdio.h>
#include<string.h>
#include<math.h>

int convertion(int x, int k){
    int ans = 0;
    int power = pow(2, k-1);
    int rem = 0;
    while(x != 0){
        rem = x%2;
        ans = ans + rem*power;
        power = power/2;
        x = x/2;
    }
    return ans;
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        char a[65537];
        char ans[65537];
        int k;
        scanf("%d", &k);
        scanf("%s", a);
        int len = strlen(a);
        for( int i = 0; i < len; i++){
            int x = convertion(i, k);
            ans[x] = a[i];
        }
        ans[len] = '\0';
        printf("%s\n", ans);
    }
}
