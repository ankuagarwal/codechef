/**
 *
 *  Copyright (c) 10th Oct. All rights reserved.
 *
 *	@filename: StrangeMatrix.cpp
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

long long unsigned int gcd (long long unsigned int a, long long unsigned int b){
	if ( b == 0)
		return a;
	else 
		return gcd (b, a % b);
}

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		long long unsigned int n;
		long long unsigned int m;
		scanf ("%llu %llu", &n, &m);

		if (n == 1) {
			printf("%llu\n", m);
			continue;
		}

		if (m == 1){
			printf("%llu\n", n);
			continue;
		}

		long long unsigned int g = gcd (n - 1, m - 1);
		printf("%llu\n", g + 1);
	}    
}