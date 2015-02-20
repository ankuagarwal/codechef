#include <cstdio>
#include <cstdlib>

main(){
  int t;
  scanf ("%d", &t);
  while ( t--){
     long long unsigned int n;
     scanf ("%llu", &n);
     if (n%2 == 0)
         printf ("%llu\n", n);
     else printf ("%llu\n", n-1);
  }
}
