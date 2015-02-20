//
//  File.cpp
//  myProject
//
//  Created by Ankit Agarwal on 03/05/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

int A[26];

void initialize(){
    for(int i = 0; i < 26; i++)
        A[i] = 0;
}

void print(){
    for (int i = 0 ; i < 26; i++)
        printf("%c %d ", 'a'+i, A[i]);
    printf("\n");
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    char c;
    c = getchar();
    while (t--){
        initialize();
        c = getchar();
             
        while (c != EOF && c != '\n'){
            if( c == ' '){
                c = getchar();
                continue;
            }
            A[c-'a']++;
            c = getchar();
        }
        
        int n;
        scanf("%d", &n);
        c = getchar();
        for(int i = 0 ; i < n; i++){
            c = getchar();
            while (c != EOF && c != '\n'){
                A[c-'a']--;
                c = getchar();
         
            }
        }

        bool cond = true;
        for(int i = 0; i < 26; i++){
            if(A[i] < 0){
                printf("NO\n");
                cond = false;
                break;
            }
        }
        if(cond)
            printf("YES\n");
    }
    
}
