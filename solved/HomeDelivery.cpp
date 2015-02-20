#include <cstdio>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N[110][110];
int nodes[110];
int n;

void initialize(){
   for( int i = 0; i < 110; i++)
      for( int j = 0; j < 110; j++)
        N[i][j] = 0;

   for( int i = 0; i < 110; i++)
        nodes[i] = 0;
}


void solve(){
   int g = 1;

   for( int i = 0; i < n; i++){
       if(nodes[i] == 0){
          queue <int> q;
          q.push(i);

          while (!q.empty()){
            int e = q.front();
            q.pop();
            nodes[e] = g;
            for( int j = 0; j < n; j++){
               if ((N[e][j] == 1) && (nodes[j] == 0))
                  q.push(j);
            }
         }

         int temp;
         for( int j = 0; j < n; j++){
            if( nodes[j] == g){
               temp = j;
               break;
            }
         }

         for( int j = temp; j < n; j++){
            if( nodes[j] == g){
               N[temp][j] = 1;
            }
         }

         for( int j = temp; j < n; j++){
            if(nodes[j] == g){
               for( int k = 0; k < n; k++){
                  N[j][k] = N[temp][k];

               }
            }
         }
       }
       g++;
     }
}

main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while ( t--){
      initialize();
      int m;
      scanf ("%d %d", &n, &m);
      int x, y;
      for ( int i = 0; i < m; i++){
          scanf("%d %d", &x, &y);
          N[x][y] = 1;
          N[y][x] = 1;
      }
      solve();
      int q;
      scanf("%d", &q);
      for( int i = 0; i < q; i++){
         scanf("%d %d", &x, &y);
         if((N[x][y] == 1) || (N[y][x] == 1))
            printf("YO\n");
         else
             printf("NO\n");
      }
  }
}
