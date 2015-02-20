#include <cstdio>
#include <cstdlib>

int N[101];
double p[101];
double ANS[101][10001];

int n;
int sum;
double ans;

void solve (){
	ANS[0][0] = 1.0;
	for (int i = 1; i <= sum; i++)
		ANS[0][i] = 0.0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= sum; j++){
			ANS[i][j] = (ANS[i-1][j] * (1.00 - p[i]));
			if (j - N[i] >= 0)
				ANS[i][j] += (ANS[i-1][j-N[i]] * p[i]);
		}
	}
	int mid;
	if (sum % 2 == 0)
	 	mid = sum/2;
	 else 
	 	mid = (sum + 1)/2;
	
	for (int i = mid; i <= sum; i++)
		ans += ANS[n][i];

	printf("%.8lf\n", ans);
}

void print (){
	for (int i = 1; i <= n; i++)
		printf("%d %f\n", N[i], p[i]);
	printf ("%d\n", sum);
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= sum; j++)
			printf("%f ", ANS[i][j]);
		printf("\n");
	}
	printf("%lf\n", ans);
}

int main (){
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		sum = 0;
		ans = 0.0;
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf ("%d", &N[i]);
			sum += N[i];
		}

		for (int i = 1; i <= n; i++){
			int x;
			scanf ("%d", &x);
			p[i] = x/100.00;
		}

		solve ();
	//	print ();
	}
}