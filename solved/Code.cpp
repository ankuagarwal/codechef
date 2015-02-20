/**
 *
 *  Copyright (c) 9th Oct. All rights reserved.
 *
 *	@filename: Code.cpp
 *	@author: Ankit Agarwal 
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

long long unsigned int Numbers[1000];

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf ("%d", &t);
    while (t--){
    	int n;
    	long long unsigned int k;
    	long long unsigned int ans;
    	scanf ("%d %llu %llu", &n, &k, &ans);
    	
    	for (int i = 0; i < n; i++){
    		scanf ("%llu", Numbers + i);
    	}

    	char ch[5];
    	scanf ("%s", ch);
    	if (ch[0] == 'X'){
    		if (k % 2 != 0){
				for (int i = 0; i < n; i++){
    				ans = ans ^ Numbers[i];
    			}
			}
			printf("%llu\n", ans);
    	} 

    	else if (ch[0] == 'A'){
    		if (k != 0){
				for (int i = 0; i < n; i++){
    				ans = ans & Numbers[i];
    			}
			}
			printf("%llu\n", ans);
    	} 

    	else if (ch[0] == 'O'){
    		if (k != 0){
				for (int i = 0; i < n; i++){
    				ans = ans | Numbers[i];
    			}
			}	
			printf("%llu\n", ans);	
    	}
    }	    
}