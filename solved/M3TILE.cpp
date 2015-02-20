#include<cstdio>
#include<cstdlib>

int a[31];

void initialize(){
    for( int i = 1; i <= 30; i = i + 2)
            a[i] = 0;
    a[0] = 1;
    for( int i = 2; i <= 30; i = i + 2){
        if( ((i-4) < 0)  && ((i-6) < 0) ){
            a[i] = 3 * a[i-2] ;
        }
        else if ( (i-6) < 0 ) {
            a[i] = 3 * a[i-2] + 3 * a[i-4] - 1;
        }
        else
            a[i] = 3* a[i-2] + 3 * a[i-4] - a[i-6];
    }

}
main(){
    initialize();
    int n;
    scanf("%d", &n);
    while ( n != -1){
        printf("%d\n", a[n]);
        scanf("%d", &n);
    }
}
