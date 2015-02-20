//
//  DessertWizard.cpp
//
//  Created by Ankit Agarwal on 13/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>

long long int N[10004];
long long int LeftMinArray[10004];
long long int LeftMaxArray[10004];
long long int RightMinArray[10004];
long long int RightMaxArray[10004];

int n;

long long int min (long long int a, long long int b){
	if (a < b)
		return a;
	else
		return b;
}

long long int max (long long int a, long long int b){
	if (a > b)
		return a;
	else
		return b;
}

long long int absoluteDifference (long long int a, long long int b){
	long long int maxvalue = max (a, b);
	long long int minvalue = min (a, b);
	return maxvalue - minvalue;
}

void calculateLeftArrays (){
	LeftMinArray[0] = N[0];
	LeftMaxArray[0] = N[0];
	for (int i = 1; i < n; i++){
		LeftMinArray[i] = (min (LeftMinArray[i-1], 0)) + N[i];
		LeftMaxArray[i] = (max (LeftMaxArray[i-1], 0)) + N[i];
	}
}

void calculateRightArrays (){
	RightMinArray[n-1] = N[n-1];
	RightMaxArray[n-1] = N[n-1];

	for (int i = n-2; i >= 0; i--){
		RightMinArray[i] = (min (RightMinArray[i+1], 0)) + N[i];
		RightMaxArray[i] = (max (RightMaxArray[i+1], 0)) + N[i];
	}
}

void solve (){
	calculateLeftArrays();
	calculateRightArrays();

	long long int ans = 0;
	for (int i = 0; i < n-1; i++){
        ans = max (ans, (absoluteDifference (LeftMaxArray[i], RightMinArray[i+1])));
		ans = max (ans, (absoluteDifference (LeftMinArray[i], RightMaxArray[i+1])));
	}
	printf ("%lld\n", ans);
}

int main (){

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%lld", N + i);
		solve();
	}
}