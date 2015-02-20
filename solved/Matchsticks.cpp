//
//  Matchsticks.cpp
//
//  Created by Ankit Agarwal on 15/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

int MAX;
int matchStick[100001];
int minRangeTree[400001];
int maxRangeTree[400001];


void preprocess(int n){
   	MAX = 2* pow(2, ((log10(n)/log10(2))+1));
    
    for(int i = 0; i <= MAX ; i++){
        minRangeTree[i] = -1;
        maxRangeTree[i] = -1;
    }
}

void initializeMin(int node , int i, int j){
    if(node > MAX || i > j)
        return;
    if(i == j){
        minRangeTree[node] = i;
        return;
    }
    
    initializeMin (2 * node, i, (i+j)/2);
    initializeMin (2 * node + 1 , 1 + (i+j)/2, j);
    
    if(matchStick[minRangeTree[2 * node]] < matchStick[minRangeTree[2 * node + 1]]){
        minRangeTree[node] = minRangeTree[2 * node];
    }
    else {
        minRangeTree[node] = minRangeTree[2 * node + 1];
    }
}

void initializeMax(int node , int i, int j){
    if(node > MAX || i > j)
        return;
    if(i == j){
        maxRangeTree[node] = i;
        return;
    }
    
    initializeMax (2 * node, i, (i+j)/2);
    initializeMax (2 * node + 1 , 1 + (i+j)/2, j);
    
    if(matchStick[maxRangeTree[2 * node]] > matchStick[maxRangeTree[2 * node + 1]]){
        maxRangeTree[node] = maxRangeTree[2 * node];
    }
    else {
        maxRangeTree[node] = maxRangeTree[2 * node + 1];
    }
}

int queryMin(int node, int i, int j, int a, int b){
    if(node > MAX || i > j)
        return -1;
    if(i > b || j < a)
        return -1;
    if(a <= i && j <= b)
        return minRangeTree[node];
    
    int p1 = queryMin(2 * node, i, (i+j)/2, a, b);
    int p2 = queryMin(2 * node + 1, 1 + (i+j)/2, j, a, b);
    
    if(p1 == -1)
        return p2;
    if(p2 == -1)
        return p1;
    if(matchStick[p1] <= matchStick[p2])
        return p1;
    else
        return p2;
}

int queryMax(int node, int i, int j, int a, int b){
	if(node > MAX || i > j)
        return -1;
	
    if(i > b || j < a)
        return -1;
    
    if(a <= i && j <= b)
        return maxRangeTree[node];
    
    int p1 = queryMax(2 * node, i, (i+j)/2, a, b);
    int p2 = queryMax(2 * node + 1, 1 + (i+j)/2, j, a, b);
    
    if(p1 == -1)
        return p2;
    
    if(p2 == -1)
        return p1;
    
    if(matchStick[p1] >= matchStick[p2])
        return p1;
    else
        return p2;
}

void print(int n){
    for(int i = 0; i < n; i++)
        printf("%d %d\n", i, matchStick[i]);
    printf("\n\n");
    for(int i = 1; i < MAX; i++)
        printf("%d %d \n", i, minRangeTree[i]);
    printf("\n\n");
    for(int i = 1; i < MAX; i++)
        printf("%d %d \n", i, maxRangeTree[i]);
    printf("\n\n");
}


int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    preprocess(n);
    for(int i = 0; i < n; i++)
        scanf("%d", matchStick + i);
    initializeMin(1, 0, n-1);
    initializeMax(1, 0, n-1);
    //   print(n);
    
    int q, l, r;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &l, &r);
        
        int max1 = queryMax(1, 0, n-1, 0, l-1);
        int max2 = queryMax(1, 0, n-1, r+1, n-1);
        int finalMax1;
        if(matchStick[max1] > matchStick[max2])
            finalMax1 = matchStick[max1];
        else
            finalMax1 = matchStick[max2];
        
        int min = queryMin(1, 0, n-1, l, r);
        int max3 = queryMax(1, 0, n-1, l, r);
        double finalMax2;
        if((matchStick[max3]-matchStick[min]) > 2 * finalMax1)
            finalMax2 = 0.5 * (matchStick[max3]-matchStick[min]) ;
        else
            finalMax2 = 1.0 * finalMax1;
        
        printf("%.1f\n", finalMax2 + 1.0 *  matchStick[min]);
    }
}