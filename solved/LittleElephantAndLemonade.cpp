#include <cstdio>
#include <cstdlib>

int input[101][102];
int order[10001];

int n;
int m;

void sort (){
	for (int i = 0; i < n; i++){
		int count = input[i][0];
		for (int j = 1; j <= count; j++){
			for (int k = 1; k <= count; k++){
				if (input[i][j] < input[i][k]){
					int t = input[i][j];
					input[i][j] = input[i][k];
					input[i][k] = t;
				}
			}
		}
	}
}

void print (){
	for (int i = 0; i < n; i++){
		int count = input[i][0];
		printf ("%d ", count);
		for (int j = 1; j <= count; j++)
			printf ("%d ", input[i][j]);
		printf("\n");
	}
	printf ("\n");
}

void solve (){
	int sum = 0;
	for (int i = 0; i < m; i++){
		int index = order[i];
		int count = input[index][0];
		if (count > 0){
			sum += input[index][count];
			input[index][0]--;
		}
	}
	printf ("%d\n", sum);
}

int main (){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			scanf ("%d", order + i);
		}
		for (int i = 0; i < n; i++){
			int x;
			scanf ("%d", &x);
			input[i][0] = x;
			for (int j = 1; j <= x; j++){
				scanf ("%d", &input[i][j]);
			}
		}
		sort ();
		solve ();
	}
}