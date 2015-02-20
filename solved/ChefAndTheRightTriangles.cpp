/**
 *
 *  Copyright (c) 18th Aug. All rights reserved.
 *
 *	@filename: ChefAndTheRightTriangles.cpp
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

bool solve (int x1, int y1, int x2, int y2, int x3, int y3){
	int x1x2 = x1 - x2;
	int x2x3 = x2 - x3;
	int x3x1 = x3 - x1;

	int y1y2 = y1 - y2;	
	int y2y3 = y2 - y3;	
	int y3y1 = y3 - y1;	

	if (x1x2 == 0){
		if (y2y3 == 0 || y3y1 == 0)
			return true;
	}

	if (x3x1 == 0){
		if (y2y3 == 0 || y1y2 == 0)
			return true;
	}

	if (x2x3 == 0){
		if (y1y2 == 0 || y3y1 == 0)
			return true;
	}

	if (y1y2 * y2y3 + x1x2 * x2x3 == 0 )
		return true;
	
	if (y1y2 * y3y1 + x1x2 * x3x1 == 0 )
		return true;

	if (y2y3 * y3y1 + x3x1 * x2x3 == 0 )
		return true;

	if (y2y3 * y1y2 + x1x2 * x2x3 == 0 )
		return true;
	
	if (y3y1 * y1y2 + x3x1 * x1x2 == 0 )
		return true;
	
	if (y3y1 * y2y3 + x3x1 * x2x3 == 0 )
		return true;
	
	return false;

}

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int n;
	scanf ("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2, x3, y3;
		scanf ("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		if (solve(x1, y1, x2, y2, x3, y3))
			ans++;
	}   
	printf("%d\n", ans);
}