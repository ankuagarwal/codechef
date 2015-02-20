#include<stdio.h>

int friends;
int matrix[101][101];
int friendcount[101];
int color[101];
int indvcost[101];
int queue[1000000];

int function(int i){
    int  cost = 0;
    color[i] = 1;
    int count = 1;
    queue[count] = i;
    indvcost[i] = 0;
    int start = 1;
    while(start <= count){
        int dequeue = queue[start];
        for( int j = 1; j<= friendcount[dequeue]; j++){
            if(color[matrix[dequeue][j]] == 0){
                color[matrix[dequeue][j]] = 1;
                indvcost[matrix[dequeue][j]] = indvcost[dequeue] +1;
                queue[++count] = matrix[dequeue][j];
            }
        }
        color[queue[start]] = 2;
        start++;
    }
    for( int j = 1; j <= count; j++)
        cost = cost + indvcost[queue[j]];
    return cost;
}



main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int group;
    scanf("%d", &group);
    while(group--){
        scanf("%d", &friends);
        char c;
        int maxcount = 0;
        int numberofmax= 1;
        int maxid[friends];
        for( int i = 1; i <= friends; i++){
            int count = 1;
            scanf("%d", &matrix[i][count]);
            scanf("%c", &c);
            while( c != '\n') {
                count++;
                scanf("%d", &matrix[i][count]);
                scanf("%c", &c);
            }
            friendcount[i] = count;
        }

        int mincost = 1000000000;
        int id = 0;
        for( int i = 1; i <= friends; i++){
            for( int j = 1; j<= friends; j++){
                color[j] = 0;
                indvcost[j]  = 0;
             }
           int cost = function(i);
           if(cost < mincost) {
                mincost = cost;
                id = i;
            }
        }
        double avg = (mincost * 1.0)/friends;
        printf("%d %.6lf\n",id, avg);
    }
}
