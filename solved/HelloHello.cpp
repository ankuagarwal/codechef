#include <cstdio>
#include <cstdlib>

int main (){
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);
	while (t--){
		float d, u;
		int n;
		scanf ("%f %f", &d, &u);
		scanf ("%d", &n);
		float min = d * u;
		int index = 0;
		for (int i = 0; i < n; i++){
			float r, c;
			int m;
			scanf ("%d", &m);
			scanf ("%f %f", &r, &c);
			float a = r * u + c/m;
			if (a < min){
				min = a;
				index = i + 1;
			}
		}
		printf ("%d\n", index);
	}
}