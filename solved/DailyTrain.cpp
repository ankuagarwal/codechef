#include<cstdio>
#include<cstdlib>
#include<cstring>


int comp[9];
long long unsigned int fact[7] = { 1, 1, 2, 6, 24, 120, 720};

void initialize(){
   for( int i = 0; i < 9; i++)
      comp[i] = 0;
}

long long unsigned int ncr(int n, int r){
    long long unsigned int a = fact[n];
    long long unsigned int b = fact[r] * fact[n-r];
    long long unsigned int c = a/b;
    return c;
}

main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   initialize();
   int x;
   int n;
   scanf("%d %d", &x, &n);
   long long unsigned int ans = 0;

   for( int j = 0; j < n; j++){
      initialize();
      char position[56];
      scanf("%s", position);

      for ( int i = 0; i < 9; i++){
        if( position[i*4+0] == '0')
           comp[i]++;
        if( position[i*4+1] == '0')
           comp[i]++;
        if( position[i*4+2] == '0')
           comp[i]++;
        if( position[i*4+3] == '0')
           comp[i]++;
        if( position[54-2*i-1] == '0')
            comp[i]++;
        if( position[54-2*i-2] == '0')
           comp[i]++;
      }
      for( int i = 0; i <  9; i++){
         if( comp[i] >= x){
            long long unsigned int a = ncr(comp[i], x);
            ans = ans + a;
         }
      }
   }
   printf("%llu\n", ans);
}
