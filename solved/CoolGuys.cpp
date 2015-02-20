/**
 *
 *  Copyright (c) 11th Sept. All rights reserved.
 *
 *	@filename: CoolGuys.cpp
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
 	if (b == 0)
 		return a;
 	else 
 		return gcd (b,a%b);
 }
 
 int main(){

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

 	int t;
 	scanf ("%d", &t);

 	while (t--){
 		long long unsigned int n;
 		scanf ("%llu", &n);

 		if (n == 1){
 			printf("1/1\n");
 			continue;
 		}
 		long long unsigned int denominator = n * n;
 		long long unsigned int numerator = n;

 		long long unsigned int prevx = n;

 		for (long long unsigned int i = 2; i <= n; i++){
 			long long unsigned int x = n/i;
 			if (x < i){
 				numerator = numerator + (prevx - x) * (i - 1);
 				break;
 			}
 			if (x == i){
 				numerator = numerator + x + (prevx - x) * (i - 1);
 				break;
 			}
 			numerator = numerator + x + (prevx - x) * (i-1);
 			prevx = x;
 		}
 		long long unsigned int g = gcd (numerator, denominator);
 		printf("%llu/%llu\n", numerator/g, denominator/g);
 		
 	}
 }