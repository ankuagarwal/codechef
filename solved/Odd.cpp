#include<iostream>
#include<stdio.h>
#include<math.h>


main(){
   long tcase = 0;
   scanf("%d", &tcase);
   long * n = new long [tcase];
   for(long i = 0 ; i < tcase; i ++)
        scanf("%d",n + i);
   for(long i = 0 ; i < tcase ; i++){
        long seq = 1;
        while ( seq <= n[i])
                seq = seq * 2;

        printf("%d\n",seq/2);

   }

}
