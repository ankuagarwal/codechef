#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int array[1000000];

inline unsigned int max(unsigned int a, unsigned int b){
    if( a> b) return a;
    else return b;
}

unsigned int function( unsigned int x){
    if ( x < 1000000) return array[x];
    return (max( x, function(x/2) + function(x/3) + function(x/4)));
}

main(){

 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    array[0]=0;
    for( int i = 1; i < 1000000; i++)
            array[i] = max(i,array[i/2]+array[i/3]+array[i/4]);

   unsigned int x;
   while (scanf("%u", &x) > 0){
            if(x < 1000000) printf("%d\n", array[x]);
            else {
                    printf("%u\n", function(x));
            }
   }
}
