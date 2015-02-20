#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 int max;
 int n;
 int left;
 int right;

void shiftRight(){
      int p = 1;
      int dummy = right;
      while( dummy > 0){
            p = p * 10;
            dummy = dummy/10;
      }
      p = p/10;
      int q2  = right/10;
      int r2  = right%10;
      right = r2* p + q2;
}

void shiftLeft(){
      int p = 1;
      int dummy = left;
      while( dummy > 0){
            p = p * 10;
            dummy = dummy/10;
      }
       p = p/10;
       int q1  = left/ p;
       int r1  = left%p;
       left = r1*10+q1;
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        max = 0;
        left = n;
        right = n;
        for( int i = 1; i <= 10; i++){
                shiftLeft();
                if( left >= max)  max = left;
        }
        for( int i = 1; i <= 10; i++){
                shiftRight();
                if( right >= max)  max = right;
        }

        left = n;
        shiftLeft();
        right = left;
        shiftRight();
        if(right >= max) max = right;

        right = n;
        shiftRight();
        left = right;
        shiftLeft();
        if(left >= max) max = left;

        printf("%d\n", max);
    }
}
