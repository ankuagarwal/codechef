#include <cstdio>
#include <cstdlib>


main(){
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);

   int t;
   scanf ("%d", &t);
   while (t--){
      long long unsigned int n;
      long long unsigned int m;
      scanf ("%llu %llu", &n, &m);
      long long unsigned int a = 1;
      long long unsigned int b = 1;
      for ( int i = 1; i < n; i++){
         long long unsigned int x = (a + b) % m;
         long long unsigned int y = (a + 2 * b) %m ;
         a = x;
         b = y;
      }
      printf ("%llu/%llu\n", a, b);
   }
}
