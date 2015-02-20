#include <cstdio>
#include <cstdlib>

int gcd (int a, int b){
   if( b == 0) return a;
   else
      return gcd(b, a%b);
}

int solve (int n){
   int ans = 1;
   int l = n-1;
   for ( int i = 2; i <= l; i++ ){
      if(gcd(n,i) == 1) ans ++;
   }
   return ans;
}

main(){

     freopen ( "input.txt", "r", stdin );
     freopen ( "output.txt", "w", stdout );

     int t;
     scanf( "%d", &t);
     while ( t--){
         int n;
         scanf( "%d", &n);
         int ans = solve(n);
         printf("%d\n", ans);
     }
}
