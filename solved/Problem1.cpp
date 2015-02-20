#include<cstdio>
#include<cstdlib>
#include<cstring>

char a[100000];
char b[100000];
char c[100000];


main(){
    int t;
    scanf("%d", &t);
    while ( t--){
        scanf("%s", &a[0]);
        scanf("%s", &b[0]);

        int la = strlen(a);
        int lb = strlen(b);
        int max = ((la >= lb) ? la : lb);
        int carry = 0;
        int i = 0;
        for( i; i < max; i++){
            if( a[i] == '\0'){
                int sum = b[i]-'0' + carry;
                c[i] = sum % 10 + '0';
                carry = sum/10;
                continue;
            }
            if( b[i] == '\0'){
                int sum = a[i]-'0' + carry;
                c[i] = sum % 10 + '0';
                carry = sum/10;
                continue;
            }
            int sum = a[i]-'0' + b[i]-'0' + carry;
            c[i] = sum % 10 + '0';
            carry = sum/10;
        }
        if( carry != 0)
            c[i++] = carry + '0';
        c[i] = '\0';
        int len = strlen (c);
        for(  i = 0; i < len; i++)
                if( c[i] != '0') break;
        printf("%s\n", &c[i]);
    }
}
