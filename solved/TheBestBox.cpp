#include<stdio.h>
#include<math.h>

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t --){
        long p;
        long s;
        scanf("%d", &p);
        scanf("%d", &s);

        double d = pow (( p*p - 24 * s), 0.5);
        double z = (p - d ) / 12;
        double vol = 0.25 *(4 * z * z * z - p * z * z + 2 * s * z);
        printf("%.2f\n", vol);
    }
}

