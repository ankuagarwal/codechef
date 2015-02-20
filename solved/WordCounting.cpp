#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

int letter[52];
long long unsigned int fact[501];
long long unsigned int inverse[11];
int x;
int y;
int prod = 1;

void inverseFunction(int a, int b){
   long long unsigned int p = a;
   while ( 2 * b <= y){
      p = (p * p) % 1000000007 ;
      b = 2 * b;
   }
   y = y-b;
   prod = (prod * p) % 1000000007;
}

void preinialize(){
    fact[0] = 1;
    for( int i = 1; i <= 500; i++)
        fact[i] = (fact[i-1] * i) % 1000000007;
    inverse[0] = 1;
    inverse[1] = 1;
    for( int i = 2; i < 11; i++){
         x = fact[i];
         y = 1000000005;
         while ( y > 0)
           inverseFunction(x, 1);
         inverse[i] = prod;
         prod = 1;
    }
}

void initialize(){
   for ( int i = 0; i < 52; i++ )
        letter[i] = 0;
}

void solve(int wordcount){
    int ans = fact[wordcount];
    for( int i = 0; i < 52; i++)
        ans = (ans * inverse[letter[i]]) % 1000000007;
    printf("%d\n", ans);
}

main(){

   freopen( "input.txt", "r", stdin);
   freopen( "output.txt", "w", stdout);

   preinialize();
   int t;
   scanf("%d", &t);
   char c[501];
   while ( t--){
      initialize();
      scanf("%s", &c);
      int len = strlen(c);
      for( int i = 0; i < len; i++){
         if( 'a' <= c[i] && c[i] <= 'z')
             letter[c[i] - 'a']++;
         else letter[c[i] - 'A' + 26]++;
      }
      solve(len);
   }
}
