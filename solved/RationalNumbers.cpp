#include <cstdio>
#include <cstdlib>

int primeNumbers[1000001];
long long int phi[1000001];

void initialize(){
    phi[0] = 0;
    phi[1] = 0;
    for( int i = 2; i < 1000001; i++){
      primeNumbers[i] = 0;
      phi[i] = i;
    }
    for( int i = 2; i < 1000001; i++){
       if( primeNumbers[i] == 0){
         primeNumbers[i] = i;
         phi[i] = i-1;
         for( int k = i + i; k < 1000001; k = k + i){
             primeNumbers[k] = i;
             phi[k] = (phi[k]/i) * ( i-1);
         }
      }
   }

   for( int i = 1; i < 1000001; i++)
      phi[i] = phi[i-1] + phi[i];
}

main(){
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);

   initialize();
   int t;
   scanf("%d", &t);
   while ( t--){
      int n;
      scanf("%d", &n);
      printf("%llu\n", phi[n]);
   }
}
