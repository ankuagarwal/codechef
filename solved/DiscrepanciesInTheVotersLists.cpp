#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int count = 0;
int n1, n2, n3;
long long check[150003];
long long arr1[50001];
long long arr2[50001];
long long arr3[50001];

void function ( int i1, int i2, int i3){
    if(i1 < n1 && i2 < n2 && i3 < n3){
        long long a1 = arr1[i1];
        long long a2 = arr2[i2];
        long long a3 = arr3[i3];

        if(a1 == a2 && a2 == a3){
                check[count] = a1;
                count++;
                return function( i1+1, i2+1, i3+1);
        }

        if(a1 == a2 && a1 < a3){
                check[count] = a1;
                count++;
                return function (i1+1, i2+1, i3);
        }

        if(a2 == a3 && a2 < a1){
                check[count] = a2;
                count++;
                return function (i1, i2+1, i3+1);
        }

        if(a1 == a3 && a1 < a2){
                check[count] = a1;
                count++;
                return function (i1+1, i2, i3+1);
        }

        if(a1 == a2 && a1 > a3)
                return function(i1, i2, i3+1);
        if(a1 == a3 && a1 > a2)
                return function(i1, i2+1, i3);
        if(a3 == a2 && a2 > a1)
                return function(i1+1, i2, i3);

        if( a1 < a2){
                if( a1< a3)
                    return function(i1+1, i2, i3);
                else
                    return function(i1, i2, i3+1);
        }
        else {
                if( a2 < a3)
                    return function(i1, i2+1, i3);
                else
                    return function(i1, i2, i3+1);
        }
    }
    else return;
}

main(){
        freopen("input.txt", "r", stdin);
        int a;

        scanf("%d", &a);
        n1 = a+1;
        scanf("%d", &a);
        n2 = a+1;
        scanf("%d", &a);
        n3 = a+1;

        for( int i = 0; i < (n1-1); i++)
            scanf("%d",arr1+i);

        for( int i = 0; i < (n2-1); i++)
            scanf("%d",arr2+i);

        for( int i = 0; i < (n3-1); i++)
            scanf("%d",arr3+i);

        arr1[n1-1] = 4294967295;
        arr2[n2-1] = 4294967295;
        arr3[n3-1] = 4294967295;

        function(0, 0, 0);

        printf("%d\n", (count-1));
        for(int i = 0; i < (count-1); i++)
            printf("%d\n", check[i]);

}
