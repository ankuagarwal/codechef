//
//  Predictopus.cpp
//
//  Created by Ankit Agarwal on 13/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		double p;
		scanf ("%lf", &p);
		if (p > 0.5){
			printf ("%lf\n", 30000 * p - 20000 * p * p );
		}
		else {
			printf ("%lf\n", 10000 + 10000 * p - 20000 * p * p);
		}
	}
}