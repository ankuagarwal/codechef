#include <cstdio>
#include <cstdlib>
#include <cmath>

int N[100001];
int n;
int d;	

void merge (int a, int mid, int b){
	int l1 = mid - a + 1;
	int l2 = b - mid ; 
	int N1[l1 + 2];
	int N2[l2 + 2];
	for (int i = 1; i <= l1; i++)
		N1[i] = N[a + i - 1];
	for (int i = 1; i <= l2; i++)
		N2[i] = N[mid + i];
	N1[l1 + 1] = 1000000001;
	N2[l2 + 1] = 1000000001;
	int i = 1;
	int j = 1;
	for (int k = a; k <= b; k++){
		if (N1[i] <= N2[j]){
			N[k] = N1[i];
			i++;
		}
		else {
			N[k] = N2[j];
			j++;
		}
	}
}

void mergeSort (int a, int b){
	if (a < b){
		int mid = (a + b)/2;
		mergeSort (a, mid);
		mergeSort (mid + 1, b);
		merge (a, mid, b);
	}
}

void print (){
	for (int i = 0; i < n; i++)
		printf ("%d ", N[i]);

}

void solve (){
	mergeSort (0, n-1);
	int i = 0; 
	int count = 0;
	while (i <= n - 2){
		int diff = N[i+1] - N[i];
		if (diff <= d){
			count++;
			i++;
		}
		i++;
	}
	printf ("%d\n", count);
}

int main (){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	scanf ("%d", &n);
	scanf ("%d", &d);
	for (int i = 0; i < n; i++)
		scanf ("%d", N + i);
	solve ();
}