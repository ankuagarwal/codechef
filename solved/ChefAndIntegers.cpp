/**
 *
 *  Copyright (c) 11th Sept. All rights reserved.
 *
 *	@filename: ChefAndIntegers.cpp
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

long long int n;
long long int input[100001];
long long int countValues = 0;
long long int k;

void merge(long long int p, long long int q, long long int r){
    long long int n1= q-p+1;
    long long int n2 = r- q;
    long long int l1[n1+2];
    long long int l2[n2+2];
    for (long long int i = 1; i <= n1; i++)
            l1[i] = input[p+i-1];
    l1[n1+1] = 0;
    for (long long int i = 1; i <= n2; i++)
            l2[i] = input[q+i];
    l2[n2+1] = 0;
    long long int i = 1;
    long long int j = 1;
    for (long long int k = p ; k <= r; k++){
        if(l1[i] <= l2[j]){
            input[k] = l1[i];
            i++;
        }
        else{
            input[k] = l2[j];
            j++;
        }
    }
}

void mergesort(long long int p , long long int r){
    if( p < r){
        long long int q = (p+ r)/2;
        mergesort(p, q);
        mergesort(q+1, r);
        merge(p,q,r);
    }
}

long long int absoluteValue (long long int a){
	if (a < 0)
		return 0 - a;
	return a;
}

void print (){
	for (int i = 0; i < countValues; i++)
		printf("%lld ", input[i]);
}

long long int solve (){
	mergesort(0, countValues -1);
	long long int ans = 0;

	for (int i = 0; i < k ; i++){
		ans += input[i];
	}
	long long int a = absoluteValue(ans);
	return a;
}  


int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf ("%lld", &n);
    for (long long int i = 0; i < n; i++){
    	long long int x;
    	scanf("%lld", &x);
    	if (x < 0){
    		input[countValues++] = x;
    	}
    }
	scanf ("%lld", &k);
	long long int ans = 0;
	if (k > countValues){
		long long int a = 0;
		for (long long int i = 0; i < countValues; i++)
			a += input[i];
		ans = absoluteValue (a);
	}
	else {
		ans = solve ();
	}   
	printf("%lld\n", ans);
}