#include <cstdio>
#include <cstdlib>

main(){
   int t;
   scanf ("%d", &t);
   while ( t--){
      int n;
      scanf ("%d", &n);

//      if( n == 1) {
//         printf ("UNFIT\n");
//         continue;
//      }

      int max = -1;
      int min = -1;
      int premin = -1;
      int diff = -1;
      scanf ("%d", &min);
      max = min;

      int x;
      for (int i = 2; i <= n; i++){
         scanf ("%d", &x);
         if ( x > max ){
            max = x;
            if( (max- min) > diff )
               diff = max - min;
         }
         if (x < min) {
            min = x;
            max = x;
         }
      }
      if( diff == -1)
        printf("UNFIT\n");
      else
        printf ("%d\n", diff);
   }
}
