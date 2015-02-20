#include <cstdio>
#include <cstdlib>

long long unsigned int N[10001];
long long unsigned int ans[10001];
int n;

long long unsigned int max (long long unsigned int a, long long unsigned int b){
	if (a > b)
		return a;
	return b;
} 

void print (){
	for (int i = n-1; i >=0; i--){
		printf ("%llu ", ans[i]);
	}
}

void solve (){
	ans[0] = N[0];
	ans[1] = max (N[0], N[1]);
	for (int i = 2; i < n; i++){
		ans [i] = max (N[i] + ans[i-2], ans[i-1]);
	}
	printf ("%llu\n", ans[n-1]);
}

int main (){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	for (int j = 1; j<=t; j++){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++){
			scanf ("%llu", N + i);
		}
		printf ("Case %d: ", j);
		if (n == 0){
			printf("%d\n", 0);
			continue;
		}
		if (n == 1){
			printf ("%llu\n", N[0]);
			continue;
		}
		solve ();
		//print ();
	}
}