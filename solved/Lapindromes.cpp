//
//  Lapindromes.cpp
//
//  Created by Ankit Agarwal on 13/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[1001];

int letters[26];

void initialize(){
	for (int i = 0; i < 26; i++)
		letters[i] = 0;
}

void solve(){
	int len = strlen(s);
	int mid = len/2;
	for (int i = 0; i < mid; i++){
		letters[s[i]-'a']++;
		letters[s[len-1-i]-'a']--;
	}

	for (int i = 0; i < 26; i++){
		if (letters[i] > 0){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		initialize();

		scanf ("%s", s);
		solve();
	}	
}