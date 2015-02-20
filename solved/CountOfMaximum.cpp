#include<cstdio>
#include<cstdlib>

int a[10001];

void initialize(){
   for( int i = 1; i < 10001; i++)
       a[i] = 0;
}

int findMax(int n){
   int max = 1;
   for( int i = 2; i < 10001; i++){
      if( a[i] > a[max]) max = i;
   }
   return max;
}


main(){
  int t;
  scanf("%d", &t);
  while ( t--){
     initialize();
     int n;
     scanf("%d", &n);
     int x;
     for( int i = 0; i < n; i++) {
       scanf("%d", &x);
       a[x]++;
     }
     int index = findMax(n);
     printf("%d %d\n", index, a[index]);
  }
}
