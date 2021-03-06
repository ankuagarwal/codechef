//
//  WString.cpp
//
//  Created by Ankit Agarwal on 13/07/13.
//  Copyright (c) 2013 Ankit. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

char S[10001];
int MaxArray[10001][26];
int Index[100001];

int len;
int count;

int max (int a, int b){
	if (a > b)
		return a;
	else 
		return b;
}

void initialize (){
	len = strlen (S);
	count = 0;
	for (int i = 0; i < len; i++){
		for (int j = 0; j < 26; j++){
			MaxArray[i][j] = 0;
		}
	}

	if (S[0] != '#'){
		MaxArray[0][S[0]-'a'] = 1;
	}

	for (int i = 1; i < len; i++){
		for (int j = 0; j < 26; j++){
			MaxArray[i][j] = MaxArray[i-1][j];
		}
		if (S[i] == '#'){
			Index[count++] = i;
		}
		else {
			MaxArray[i][S[i]-'a']++;
		}
	}
}

void print (){
	for (int i = 0; i < len; i++){
		printf ("%d 	", i);
		for (int j = 0; j < 26; j++){
			printf ("%d ", MaxArray[i][j]);
		}
		printf ("\n");
	}
}

void solve (){
	int ans = 0;
	for (int i = 0; i <= (count-3); i++){
		int index1 = Index[i];
		int index2 = Index[i+1];
		int index3 = Index[i+2];
		int index4  = len;
		
		if (index1 == 0 || index1 + 1 == index2 || index2 + 1 == index3 || index3 + 1 == index4)
			continue;

		bool cond = false;
		for (int j = 0; j < 26; j++){
			if (MaxArray[index1-1][j] > 0){
				cond = true;
				break;
			}
		}
		if (!cond)
			continue;

		int a1 = 0;
		int a2 = 0;
		int a3 = 0;
		int a4 = 0;

		for (int j = 0; j < 26; j++){
			a1 = max (a1, MaxArray[index1-1][j]);
			a2 = max (a2, MaxArray[index2-1][j] - MaxArray[index1][j]);
			a3 = max (a3, MaxArray[index3-1][j] - MaxArray[index2][j]);
			a4 = max (a4, MaxArray[index4-1][j] - MaxArray[index3][j]);
		}
		
		ans = max (ans, a1 + a2 + a3 + a4 + 3);
	}

	printf ("%d\n", ans);
}

int main (){

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		scanf ("%s", S);

		initialize ();
		solve ();
	}
}
