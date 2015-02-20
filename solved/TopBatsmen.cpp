#include <cstdio>
#include <cstdlib>

int ncr (int n, int r){
   int ans = 1;
   for ( int i = n; i > (n-r); i--)
      ans = ans * i;
   for ( int i = r; i > 0; i--)
      ans = ans/ i;
    return ans;
}
main(){
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);

   int t;
   scanf ("%d", &t);
   while ( t--){
      int n[11];
      for ( int i = 0; i < 11; i++)
          scanf ("%d", n+i);
      int k;
      scanf ("%d", &k);
      for ( int i = 0; i < 11; i++){
          for ( int j = 0; j < 11; j++){
             if ( n[i] > n[j]) {
                int t = n[i];
                n[i] = n[j];
                n[j] = t;
             }
          }
      }

      int x = n[k-1];
      int in = 0;
      int out = 0;
      for ( int i = 0; i < k; i++)
         if ( n[i] == x) in++;
      for ( int i = k; i < 11; i++)
          if (n[i] == x) out++;

      int ans = ncr ( in+out, in);
      printf ("%d\n", ans)    ;
   }
}
