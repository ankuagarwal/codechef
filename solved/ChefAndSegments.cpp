#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <utility>
 
using namespace std;

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int numbers[100001];
int n;

int frequency[101][25];
int cummulativeFrequency[100001][25];

void print (){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 25; j++)
			printf("%d ", frequency[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void preprocess (){
	for (int i = 0; i < 101; i++){
		for (int j = 0; j < 25; j++){
			frequency[i][j] = 0;
		}
	}

	for (int i = 0; i < 100001; i++){
		for (int j = 0; j < 25; j++){
			cummulativeFrequency[i][j] = 0;
		}
	}

	for (int i = 1; i <= 100; i++){
		int d = i;
		int j = 0;
		while (d >= prime[j]){
			if (d % prime[j] == 0){
				d = d / prime[j];
				frequency[i][j]++;
			}
			else {
				j++;
			}
		}
	}

}

void initialize (){
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 25; j++){
			cummulativeFrequency[i][j] = cummulativeFrequency[i-1][j] + frequency[numbers[i]][j];
		}
	}
}	

long long unsigned int multiplyValues (long long unsigned int a, long long unsigned int b, long long unsigned int modulo){
	if (b == 0)
		return 1 % modulo;
	long long unsigned int ans = 1;
	long long unsigned int x = a;
	while(b > 0){
		if (b&1) 
			ans = (ans * x) % modulo;
		b >>= 1;
		x = (x * x) % modulo;
	}
	return ans;
}

void solve (int left, int right, int modulo){
		long long unsigned int ans = 1;

		for (int j = 0; j < 25; j++){
			int count = cummulativeFrequency[right][j] - cummulativeFrequency[left-1][j];
			long long unsigned int a1 = 1;
			if (count != 0)
				 a1 = multiplyValues (prime[j] % modulo, count, modulo);
			ans = (ans * a1) % modulo;
			if (ans == 0)
				break;
		}
		printf("%llu\n", ans % modulo);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	preprocess();

	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", numbers + i);

	initialize ();

	int t;
	scanf ("%d", &t);

	for (int i = 0; i < t; i++){
		int left,right, modulo;
		scanf ("%d %d %d", &left, &right, &modulo);
		
		solve (left, right, modulo);
	}
} 