
/**
 *
 *  Copyright (c) 3rd Jan. All rights reserved.
 *
 *	@filename: ChefAndFeedback
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


int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf ("%d", &t);

    while (t--){
    	char a[100001];
    	scanf ("%s", a);
    	int len = strlen (a);
    	bool isGood = false;
    	for (int i = 0; i <= len - 3; i ++){
    		isGood = ((a[i] == '0' && a[i+1] == '1' && a[i+2] =='0') || (a[i] == '1' && a[i+1] == '0' && a[i+2] == '1'));
    		if(isGood)
    			break;
    	}
    	if(isGood) {
    		printf("%s\n", "Good");
    	}
    	else {
    		printf("%s\n", "Bad");
    	}
    }
}

