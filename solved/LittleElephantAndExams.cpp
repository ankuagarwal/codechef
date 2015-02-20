/**
 *
 *  Copyright (c) 18th Sept. All rights reserved.
 *
 *	@filename: LittleElephantAndExams.cpp
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

int prob [50];
int A[50];
int B[50];
int n;

bool isTaken [17] = { false };

void print (){
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", prob[i], A[i], B[i]);
	for (int i = 0; i < 17; i++)
		printf("%d ", isTaken[i]);
	printf("\n");
}

double solve (int i){
	if (i >= n)
		return 1;

	double p = 0;
	if (!isTaken[A[i]]){
		isTaken[A[i]] = true;
		double p1 = solve (i+1);
		p = (prob[i]/100.00) * p1;
		isTaken[A[i]] = false;
	}

	if (!isTaken[B[i]]){	
		isTaken[B[i]] = true;
		double p2 = solve (i+1);
		p = p + ((100 - prob[i])/ 100.00) * p2;
		isTaken[B[i]] = false;
	}

	return p;
}	

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		scanf ("%d", &n);

		for (int i = 0; i < n; i++){
			scanf ("%d %d %d", prob + i , A + i , B + i);
		}

		if (n <= 16){
			double ans = solve (0);
			printf("%.9lf\n", ans);
		}
		else {
			printf("%.9lf\n", 0.0);
		}
	}    
}