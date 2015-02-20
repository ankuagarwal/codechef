#include <cstdio>
#include <cstdlib>

int main (){
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	long long unsigned int candies;
	long long unsigned int student;
	
	scanf ("%d", &t);
	while (t--){
		scanf ("%llu %llu", &candies, &student);

		if (student == 0 || candies < student){
			printf ("%d %llu\n", 0, candies);
			continue;
		}

		if (candies == 0){
			printf ("%d %d\n", 0, 0);
			continue;
		}
		long long unsigned int q = candies/student;
		long long unsigned int rem = candies%student;
		printf ("%llu %llu\n", q, rem);
	}

}