#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

main(){
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    while(1){
        if( n == 0) break;
        long long int like = 0;
        long long int dislike = 0;
        long long int current = 0;
        long long int afterRed = 0;
        long long int previous = 0;
        char choice[2];
        for( int i = 1; i <= n; i++){
            scanf("%s",&choice[0]);
            scanf("%lld",&current);
            previous = afterRed;
            if( choice[0] == 'P')
                        afterRed = current -1;
            else
                        afterRed = current + 1;
            if( afterRed >= previous){
                    long long int diff = abs( afterRed - previous);
                    if( diff == 1) {
                            like = like + 1;
                            continue;
                    }
                    if( diff % 2 == 0){
                        if( dislike >= (diff/2)){
                            dislike = dislike - diff/2;
                            like = like + diff/2;
                        }
                        else{
                            like = like + dislike + (diff - 2*dislike);
                            dislike = 0;
                        }
                    }
                    else{
                        if( dislike >= (diff/2)){
                            dislike = dislike - diff/2;
                            like = like + diff/2 +1 ;
                        }
                        else{
                            like = like + dislike + ( diff - 2*dislike);
                            dislike = 0;
                        }
                    }
            }
            else{
                    long long int diff = abs( previous - afterRed);
                    if( diff == 1) {
                            dislike = dislike + 1;
                            continue;
                      }
                    if( diff % 2 == 0){
                        if( like >= (diff/2)){
                            like = like - diff/2;
                            dislike = dislike + diff/2;
                        }
                        else{
                            dislike = dislike + like + (diff - 2*like);
                            like = 0;
                        }
                    }
                    else{
                        if( like >= (diff/2)){
                            like = like - diff/2;
                            dislike = dislike + diff/2 +1 ;
                        }
                        else{
                            dislike = dislike + like + ( diff - 2*like);
                            like = 0;
                        }
                    }
            }

        }
        printf("%lld\n", like + dislike);
        scanf("%d", &n);
    }
}
