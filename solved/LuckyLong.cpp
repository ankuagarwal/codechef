#include<cstdio>
#include<cstdlib>
#include<cstring>

main(){
 // freopen("input.txt", "r", stdin);
 // freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  char c;
  c = getchar();
  while ( t--){
     int conv = 0;
     while ( (c = getchar()) != '\n'){
         if( c != '4' && c != '7')
            conv++;
     }
     printf("%d\n", conv);
  }
}
