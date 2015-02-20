
/**
 *
 *  Copyright (c) 3rd Jan. All rights reserved.
 *
 *	@filename: PleaseLikeMe.cpp
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


int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf ("%d", &t);

    long long unsigned int l;
    long long unsigned int d;
    long long unsigned int s;
    long long unsigned int c;

    while (t--){
    	scanf ("%llu %llu %llu %llu", &l, &d, &s, &c);
    	
    	long long unsigned int ans = s;
    	long long unsigned int day = 1;
    	long long unsigned int tempC = 1 + c;

    	while (day < d && ans < l){
    		ans = ans * tempC;
    		day++;
    	}	

    	if (ans >= l){
    		printf("%s\n", "ALIVE AND KICKING");
    	}
    	else {
    		printf("%s\n", "DEAD AND ROTTING");
    	}

    }
}

