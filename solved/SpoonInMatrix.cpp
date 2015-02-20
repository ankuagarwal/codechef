#include <cstdio>
#include <cstdlib>
#include <cstring>

int r;
int c;
char M[101][101];

int horizontalCheck (int i, int j){
   if( (j+4) >= c) return -1;
   if( ((M[i][j+1] == 'P')|| (M[i][j+1] == 'p')) &&
       ((M[i][j+2] == 'O')|| (M[i][j+2] == 'o')) &&
       ((M[i][j+3] == 'O')|| (M[i][j+3] == 'o')) &&
       ((M[i][j+4] == 'N')|| (M[i][j+4] == 'n'))
    )
        return 1;
    else
        return -1;
}

int verticalCheck (int i, int j){
   if( (i+4) >= r) return -1;
   if( ((M[i+1][j] == 'P')|| (M[i+1][j] == 'p')) &&
       ((M[i+2][j] == 'O')|| (M[i+2][j] == 'o')) &&
       ((M[i+3][j] == 'O')|| (M[i+3][j] == 'o')) &&
       ((M[i+4][j] == 'N')|| (M[i+4][j] == 'n'))
   )
        return 1;
   else
        return -1;
}

int solve (){
    for ( int i = 0; i < r; i++){
        for ( int j = 0; j < c; j++){
             if(M[i][j] == 'S' || M[i][j] == 's'){
              int h = horizontalCheck(i, j);
              int v = verticalCheck(i, j);
              if(h == 1)
                    return 1;
              if(v == 1)
                    return 1;
             }
        }
    }
    return -1;
}

main(){

   freopen ( "input.txt", "r", stdin);
   freopen ( "output.txt", "w", stdout);

   int t;
   scanf("%d", &t);
   while( t--) {
       scanf("%d %d", &r, &c);
       for( int i = 0; i < r; i++)
          scanf("%s", &M[i]);

       int ans = solve();
       if( ans == 1)
          printf("There is a spoon!\n");
       else
          printf("There is indeed no spoon!\n");
   }
}
