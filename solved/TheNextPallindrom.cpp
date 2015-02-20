#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>

char **  newnumber = new char * [1000000];

void changePosition(int len, int nth){
            newnumber[nth][0] = '1';
            newnumber[nth][len] = '1';
            newnumber[nth][len+1] = '\0';
            for(int i = 1 ; i < len ; i ++)
                    newnumber[nth][i] = '0';
}

void reset ( char n[], int nth, int mid, int len, int carry){
        if (( mid - 2) < 0 ) return;
        for( int i = mid - 2 ; i >= 0 ; i --){
                newnumber[nth] [i] = ((((n[i] - '0') + carry ) %10) + '0');
                newnumber[nth][len - (i +1)] = newnumber[nth][i];
                carry = ((n[i] - '0') + carry ) /10;
        }
}

int intialCheck(char n[], int len, int nth){
        for( int i  = 0 ; i < len ; i ++){
                if((n[ i ] - '0') != 9 )
                        return 1;
        }
        changePosition(len, nth);
        return -1;
}

void palindrom(char n [], int nth){
            int len = strlen (n);
            if(intialCheck(n, len, nth) == -1 )
                    return;
            int mid = 0 ;
            mid = len / 2;
            int carry = 0;
            if ( len % 2 == 0){
                    if (( n[mid  -1] - '0') > ( n[mid] - '0')){
                            newnumber [nth][mid - 1] = n [mid - 1];
                            newnumber [nth][mid] = newnumber[nth][mid - 1];
                    }
                    else {
                            newnumber [nth][mid - 1] = ((((n[mid - 1] - '0') + 1) % 10 ) + '0');
                            newnumber [nth][mid] = newnumber[nth] [mid - 1];
                            carry =  ((n[mid - 1] - '0') + 1) / 10 ;
                    }
                    reset(n, nth, mid, len, carry);
            }
            else {
                    if (( n[mid - 1] - '0') > ( n[mid + 1] - '0')){
                            newnumber [nth][mid] = n[mid];
                            newnumber [nth][mid - 1] = n [mid - 1];
                            newnumber [nth][mid + 1] = n [mid - 1];
                    }
                    else {
                            newnumber [nth][mid] = ((((n[mid] - '0') + 1) %10 ) + '0');
                            carry = ((n[mid] - '0') + 1) / 10  ;
                            newnumber[nth] [mid - 1] = (((( n [mid -1] - '0') + carry ) % 10 ) + '0');
                            newnumber [nth][mid + 1] = newnumber[nth][mid -1];
                            carry = ((n[mid -1] - '0') + carry) / 10  ;
                    }
                    reset(n, nth, mid, len, carry);
            }
}

main(){
        int t;
        scanf ( "%d" ,  &t );
        char ** arr = new char* [t];
        for ( int i =0 ; i < t ; i++ ) {
                arr [i] = new char  [1000000];
                scanf ( "%s" , arr[i] );
        }
        for ( int i = 0 ; i < t ; i++){
                int len = strlen(arr[i]);
                newnumber[i]  = new char [len +2];
                newnumber[i][len] = '\0';
                palindrom(arr[i], i);
                printf ( "%s\n" , newnumber[i] );
        }
}
