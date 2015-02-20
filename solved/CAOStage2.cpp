/**
 *
 *  Copyright (c) 11th Sept. All rights reserved.
 *
 *	@filename: CAOStage2.cpp
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

int r, c;
char input [501][501];
int LeftHorizontalCount [502][502];
int RightHorizontalCount [502][502];
int TopVerticalCount [502][502];
int BottomVerticalCount [502][502];

int prime[501];
int primeCount[501];

int min (int a, int b){
	if (a < b)
		return a;
	return b;
}

void preprocess (){
	for (int i = 0; i < 501; i++)
		prime[i] = -1;

	prime[0] = 0;
	prime[1] = 0;

	int i = 2;
	while (i < 501){
		if (prime[i] == -1){
			prime[i] = 1;
			for (int j = 2 *i; j < 501; j = j + i)
				prime[j] = 0;
		}
		i++;
	}

	primeCount[0] = 0;
	for (int i = 1; i < 501; i++){
		if (prime[i] == 1)
			primeCount[i] = primeCount[i-1] + 1;
		else
			primeCount[i] = primeCount[i-1];
	}
}

void initialize (){
	for (int i = 0; i <= r + 1; i++){
		for (int j = 0; j <= c + 1; j++){
			LeftHorizontalCount[i][j] = 0;
			RightHorizontalCount[i][j] = 0;
			TopVerticalCount[i][j] = 0;
			BottomVerticalCount[i][j] = 0;	
		}
	}
}

void solve (){
	for (int i = r; i >= 1; i--){
		for (int j = c; j >= 1; j--){
			if (input[i][j] == '#'){
					RightHorizontalCount[i][j] = 0;
					BottomVerticalCount[i][j] = 0;
				}
				if (input[i][j] == '^'){
					RightHorizontalCount[i][j] = RightHorizontalCount[i][j+1] + 1;
					BottomVerticalCount[i][j] = BottomVerticalCount[i+1][j] + 1;
				}
		}
	}

	int count = 0;
	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (input[i][j] == '^'){
				int left = LeftHorizontalCount[i][j] - 1;
				int right = RightHorizontalCount[i][j] - 1;
				int top = TopVerticalCount[i][j] - 1;
				int bottom = BottomVerticalCount[i][j] - 1;
				int min1 = min (left, right);
				int min2 = min (top, bottom);
				int min3 = min (min1, min2);
				count += primeCount[min3];
			}
		}
	}
	printf("%d\n", count);
}

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	preprocess ();
	int t;
	scanf ("%d", &t);
	while (t--){
		scanf ("%d %d", &r, &c);
		initialize();

		char ch = getchar();
			
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				ch = getchar();
				input[i][j] = ch;
				if (ch == '#'){
					LeftHorizontalCount[i][j] = 0;
					TopVerticalCount[i][j] = 0;
				}
				if (ch == '^'){
					LeftHorizontalCount[i][j] = LeftHorizontalCount[i][j-1] + 1;
					TopVerticalCount[i][j] = TopVerticalCount[i-1][j] + 1;
				}
			}
			ch = getchar();
		}
		solve ();
	}    
}