#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct cord{
    int x;
    int y;
}ghost[31][100000];

int totalTimeGhost[31];

char maze[30][30][33];
int row, col, c, k;
int startx, starty;
int endx, endy;

queue < cord> q;

cord dummy;


bool isGhost(int t, int a, int b){
        int tc = maze[a][b][1];
        for(int i = 2; i < tc; i++){
                int ii =  maze[a][b][i];
                if(totalTimeGhost[ii] == 0){
                     if ( (ghost [ii][0].x == a) && (ghost[ii][0].y == b) )
                            return true;
                }
                 if ( (ghost [ii][(t%totalTimeGhost[ii])].x == a) && (ghost[ii][(t%totalTimeGhost[ii])].y == b) )
                            return true;
                if((ghost[ii][((t+1)%totalTimeGhost[ii])].x == a) && (ghost[ii][((t+1)%totalTimeGhost[ii])].y == b))
                            return true;
        }
        return false;
}

//void print(){
////    printf("%d\n", t);
//    for( int i = 0; i < row; i ++){
//        for( int j = 0; j < col; j++){
//            for( int k = 0; k < 33; k++)
//                printf("%d", maze[j][i][k]);
//             printf(" ");
//        }
//        printf("\n");
//    }
//    printf("\n");
//}

int function(int t, cord co){
        if( t == k) return -1;
        q.push(co);
        q.push(dummy);
        while( t <= k){
            while ( q.front().x != dummy.x ){
                cord top = q.front();
                q.pop();
                if ( ( (top.x+1) < col) && ( maze[top.x+1][top.y][0] != '#' ) && ( ! isGhost(t, top.x+1, top.y)) && ( maze[top.x+1][top.y][0]  != 'C') ){
                    if(maze[top.x+1][top.y][0] == '$') return (t+1);
                    cord toPush;
                    toPush.x = top.x+1;
                    toPush.y = top.y;
                    q.push(toPush);
                    maze[top.x][top.y][0] = 'C';
                }
                if ( ( (top.x-1) >= 0 ) && ( maze[top.x-1][top.y][0] != '#' ) && ( ! isGhost(t, top.x-1, top.y) ) && ( maze[top.x-1][top.y][0]  != 'C' ) ) {
                    if(maze[top.x-1][top.y][0]  == '$') return (t+1);
                    cord toPush;
                    toPush.x = top.x-1;
                    toPush.y = top.y;
                    q.push(toPush);
                    maze[top.x][top.y][0]  = 'C';
                }
                if ( ( (top.y+1) < row ) && ( maze[top.x][top.y+1][0]  != '#' ) && ( ! isGhost(t, top.x, top.y+1) ) && ( maze[top.x][top.y+1][0]  != 'C') ){
                    if(maze[top.x][top.y+1][0]  == '$') return (t+1);
                    cord toPush;
                    toPush.x = top.x;
                    toPush.y = top.y+1;
                    q.push(toPush);
                    maze[top.x][top.y][0]  = 'C';
                }
                if ( ( (top.y-1) >= 0 ) && ( maze[top.x][top.y-1][0]  != '#' ) && ( ! isGhost(t, top.x, top.y-1) ) && ( maze[top.x][top.y-1][0]  != 'C') ){
                    if(maze[top.x][top.y-1][0]  == '$') return (t+1);
                    cord toPush;
                    toPush.x = top.x;
                    toPush.y = top.y-1;
                    q.push(toPush);
                    maze[top.x][top.y][0]  = 'C';
                }
                if ( ! isGhost(t+1, top.x, top.y)  ){
                        q.push(top);
                        maze[top.x][top.y][0] = 'C';
                }
                else{
                    maze[top.x][top.y] [0] = '.';
                }

            }
            q.pop();
            q.push(dummy);
//print(t);
            t++;

       }
       return -1;
}

void queueEmpty(){
    while( ! q.empty())
            q.pop();
}

void initialize(){
    for( int i = 0; i < 30; i++)
        for( int j = 0; j < 30; j++)
              maze[i][j][1] = 2;
}

main(){

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        dummy.x = -1;
        dummy.y = -1;
         int t;
         scanf("%d", &t);
         while (t--){
                queueEmpty();
                initialize();
                scanf("%d %d %d %d", &row, &col, &c, &k);
                int l;
                for( int i = 1; i <= c; i++){
                        int l;
                        scanf("%d", &l);
                        int a, b;
                        int gx, gy;
                        int prevx, prevy;
                        int count = 0;
                        scanf("%d %d", &gx, &gy);
                        ghost[i][count].x = gx;
                        ghost[i][count].y = gy;
                        maze[gx][gy][2] = i;
                        maze[gx][gy][1]++;
                        count++;
                        prevx = gx;
                        prevy = gy;
                        for( int j = 2; j <=l; j++ ){
                                scanf("%d %d", &a, &b);
                                if( prevx == a){
                                        int flag = (prevy < b) ? 1 : -1;
                                        for( int k = prevy+flag; k != b; k = k + flag){
                                                ghost[i][count].x = a;
                                                ghost[i][count].y = k;
                                                int flag = 0;
                                                for( int l = 2; l < maze[a][k][1]; l++){
                                                    if(maze[a][k][l] == i){
                                                        flag = 1;
                                                        break;
                                                    }
                                                }
                                                if( flag == 0){
                                                    maze[a][k][maze[a][k][1]] = i;
                                                    maze[a][k][1]++;
                                                }
                                                count++;
                                        }
                                }
                                else{
                                        int flag = (prevx < a) ? 1 : -1;
                                        for( int k = prevx+flag; k != a; k = k + flag){
                                                ghost[i][count].x = k;
                                                ghost[i][count].y = b;
                                                int flag = 0;
                                                for( int l = 2; l < maze[k][b][1]; l++){
                                                    if( maze[k][b][l] == i){
                                                     flag = 1;
                                                     break;
                                                    }
                                                }
                                                 if( flag == 0){
                                                        maze[k][b][maze[k][b][1]] = i;
                                                        maze[k][b][1]++;
                                                 }
                                                count++;
                                        }
                                }
                                ghost[i][count].x = a;
                                ghost[i][count].y = b;
                                int flag = 0;
                                for( int l = 2; l < maze[a][b][1]; l++){
                                    if(maze[a][b][l] == i){
                                        flag =1;
                                        break;
                                    }
                                }
                                if( flag == 0){
                                        maze[a][b][maze[a][b][1]] = i;
                                        maze[a][b][1]++;
                                }
                                count++;
                                prevx= a;
                                prevy = b;
                        }
                        if( prevx == gx){
                                        int flag = (prevy < gy) ? 1 : -1;
                                        for( int k = prevy+flag; k != gy; k = k + flag){
                                                ghost[i][count].x = gx;
                                                ghost[i][count].y = k;
                                                int flag = 0;
                                                for( int l = 2; l < maze[gx][k][1]; l++){
                                                        if( maze[gx][k][l] == i){
                                                            flag = 1;
                                                            break;
                                                        }
                                                }
                                                if( flag == 0){
                                                    maze[gx][k][maze[gx][k][1]] = i;
                                                    maze[gx][k][1]++;
                                                }
                                                count++;
                                        }
                        }
                        else{
                                        int flag = (prevx < gx) ? 1 : -1;
                                        for( int k = prevx+flag; k != gx; k = k + flag){
                                                ghost[i][count].x = k;
                                                ghost[i][count].y = gy;
                                                int flag = 0;
                                                for( int l = 2; l < maze[k][gy][1]; l++){
                                                        if( maze[k][gy][l] == i){
                                                            flag = 1;
                                                            break;
                                                        }
                                                }
                                                if( flag == 0){
                                                    maze[k][gy][maze[k][gy][1]] = i;
                                                    maze[k][gy][1]++;
                                                }
                                                count++;
                                        }
                        }
                      totalTimeGhost[i] = count;
                  //    printf("%d ", count);
                }
              //  printf("\n");
//                print();
                char dum;
                scanf("%c", &dum);
                for( int i = 0 ; i < row; i++){
                        for( int j = 0; j < col; j++){
                                scanf("%c", &maze[j][i][0]);
                                if(maze[j][i][0] == '@'){
                                        startx = j;
                                        starty = i;
                                }
                                else if(maze[j][i][0] == '$'){
                                        endx = j;
                                        endy = i;
                                }
                        }
                        scanf("%c", &dum);
                }

            cord start;
            start.x = startx;
            start.y = starty;
            int tt = function(0, start);
            if(tt <= k)
                printf("%d\n", tt);
            else
                printf("-1\n");

         }
}
