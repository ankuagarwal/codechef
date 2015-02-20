//
//  WituaAndMath.cpp
//
//  Created by Ankit Agarwal on 14/05/13.
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

long long unsigned int prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int MAX = 1000000000;

long long unsigned int mult (long long unsigned int a, long long unsigned int b, long long unsigned int n){
	long long unsigned int remA = a % MAX;
    long long unsigned int quoA = a / MAX;
    
    long long unsigned int remB = b % MAX;
    long long unsigned int quoB = b / MAX;
    
    long long unsigned int result = (quoA * quoB) % n;
    
    for (int i = 1; i < 10; i++)
        result = (result * 10) % n;
    result = (result + remA * quoB + remB * quoA) % n;
    for (int i = 1; i < 10; i++)
        result = (result * 10) % n;
    result = (result + remB * remA) % n;
    return result;
}


long long unsigned int power (long long unsigned int a, long long unsigned int d, long long unsigned int n){
	if ( d == 1)
		return a;
    
	long long unsigned int ans = a % n;
	long long unsigned int count = 1;
    
	while ( 2 * count <= d){
		ans = (mult(ans, ans, n)) % n;
		count = 2 * count;
	}
    
    long long unsigned int p = power (a, d-count, n) % n ;
	ans = (mult(ans, p, n)) % n;
	return ans;
}


bool isprime (long long unsigned int n){
  	if (n != 2 && n % 2 == 0)
		return false;
    
    for (int i = 0; i < 25; i++){
        if (prime[i] == n)
            return true;
        if (n % prime[i] == 0)
            return false;
    }
    
	long long unsigned int nprime = n - 1;
    
	while (nprime % 2 == 0){
		nprime = nprime / 2;
	}
    
	for (int i = 0; i < 2; i++){
  		long long unsigned int a = rand() % (n-1) + 1;
        long long unsigned int temp = nprime;
		long long unsigned int x = power (a, temp, n);
        while (temp != n-1 && x > 0 && x != 1 && x != n-1){
            x = mult (x , x, n);
            temp *= 2;
		}
		if (x > 0 && x != n-1 && temp % 2 == 0){
			return false;
		}
	}
	return true;
}

void solve (long long unsigned int n){
  	for (long long unsigned int i = n; i > 1; i--){
		if (isprime (i)){
			printf ("%llu\n", i);
			return;
		}
	}
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf ("%d", &t);
    while (t--){
    	long long unsigned int n;
        scanf ("%llu", &n);
		solve (n);        
    } 
}
