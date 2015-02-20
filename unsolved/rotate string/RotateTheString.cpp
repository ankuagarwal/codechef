#include<cstdio>
#include<cstring>
#include<cstdlib>

char string[500001];
int f[1000002];

void Function ( char newString[]){
    int len = strlen(newString);
    int f[len];
    f[0] = -1;
    int k = -1;

    for( int q = 1; q < len; q++){
        while( k > 0 && newString[k+1] != newString[q])
                    k = f[k];
        if( newString[k+1] == newString[q])
                    k++;
        f[q] = k;
    //    if(f[q] == ((len/2)-1)) return (q-len/2+1);
    }
}

void doubleString ( ){
        int len = strlen(string);
        char newstring[2*len+1];
        for( int i = 0 ; i < len; i++){
                newstring[i] = string[i];
                newstring[len+i] = string[i];
        }
        newstring[2*len] = '\0';
        Function(newstring);
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--){
            scanf("%s", &string[0]);
            int m, p;
            scanf("%d%d", &m, &p);
            doubleString();

    }
}
