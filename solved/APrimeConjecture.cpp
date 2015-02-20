#include<stdio.h>
#include<math.h>

main(){
  //  freopen("output.txt", "w", stdout);
    int * prime = new int [1001];
    int * primenumber = new int [168];
    int count = 0;
    for( int i = 2 ; i < 1001; i++ ){
        if( prime[i] == 1)
            continue;
        prime[i] = -1;
        primenumber[count] = i;
        count++;
        for( int j = i + i ; j < 1001; j = j + i )
               prime[j] = 1;
    }

    int diff = 1000001;
    int * check = new int [diff];

    for ( long k = 0; k < 168; k++  ){
        int start = primenumber[k];
        for ( int j = start +start; j < 1000001; j = j + start)
                check[j] = 1;
    }

    int n;
    while(1){
        scanf("%d", &n);
        if( n == 0) break;

        int p1 = 0, p2= 0, p3 = 0;
        int flag = 0;
        int x = pow( (double) n, (double)1/3 );
        for ( int i = x; i >= 2; i--){
            if ( check[i] == 1 ) continue;
            int y = pow( i, 3);
            int a = n - y;
            y = pow( (double) a, (double)1/2 );
            for ( int j = y; j >= 2; j--){
                if ( check[j] == 1) continue;
                int z = pow( j , 2);
                z = a-z;
                if( z < 2) continue;
                if(check[z] == 0){
                    p1 = z;
                    p2 = j;
                    p3 = i;
                    flag = 1;
                    break;
                }
            }
            if( flag == 1) break;
        }
        printf("%d %d %d\n", p1, p2, p3);
    }
}
