//
//  CountK-Primes.cpp
//
//  Created by Ankit Agarwal on 13/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

char Prime[100002];
int N[100002];

void initialize (){
	for (int i = 0; i < 100001; i++){
		N[i] = 0;
		Prime[i] = 'X';
	}
}

void solve (){
	for (int i = 2; i < 100001; i++){
		if (Prime[i] == 'X'){
			Prime[i] = 'Y';
			N[i] = 1;
			for (int j = 2 * i; j < 100001; j = j + i){
				N[j]++;
				Prime[j] = 'N';
			}
		}
	}
}

int main (){

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	initialize ();
	solve ();

	int t;
	scanf ("%d", &t);
	while (t--){
		int a, b, k;
		scanf ("%d %d %d", &a, &b, &k);

		int ans = 0;
		for (int i = a; i <= b; i++){
			if (N[i] == k)
				ans ++;
		}
		printf("%d\n", ans);
	}
}