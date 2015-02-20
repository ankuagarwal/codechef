#include<stdio.h>

int * diff = new int[100];

void calculateDiff (int num[], int s , int c){
    if (s == 1){
            for( int i = 0 ; i <= c; i++)
                    diff[i] = 0;
            return;
    }
    int len = s-1;
    int * newdiff = new int [len];
    int diffcheck = num[1] - num[0];
    newdiff[0] = diffcheck;
    int flag = 0;
    for( int i = 1; i < len; i++){
            newdiff[i] = num[i+1] - num[i];
            if( diffcheck != newdiff[i])
                    flag = 1;
    }
    if( flag == 1)
        calculateDiff(newdiff, len, c);
    else{
         for( int i = 0; i <= c; i++)
                diff[i] = diffcheck;

        return;
    }
    diff[0] = diff[0] + newdiff[ len-1];
    for( int i = 1 ; i <= c ; i++)
            diff[i] = diff[i] + diff[i-1];

    return;
}

main(){
        int t;
        scanf("%d", &t);
        while( t--){
            int s;
            int c;
            scanf("%d", &s);
            scanf("%d", &c);
            int * num = new int[s];
            for (int i = 0; i < s; i++)
                scanf("%d", num+i);
            calculateDiff(num, s, c);
            int temp = num[s-1] + diff[0];
            for( int i = 1 ; i <= c ; i++){
                printf("%d", temp);
                printf(" ");
                temp = temp + diff[i];
            }
            printf("\n");
        }
}
