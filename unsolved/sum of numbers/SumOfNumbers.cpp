#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>

char * divide(char * num, int len){
    char * temp = new char [len];
    int count = 0;
    int carry = 0;
    for( int i = 0; i < len; i++){
        int x = (num[i] - '0')+ carry *10;
        temp[count] = (x/2) + '0';
        if(x % 2 == 0)
            carry = 0;
        else
            carry = 1;
        count++;
    }
    int flag = 0;
    int i = 0;
    for (  i ; i < len; i++){
        if (flag == 1) break;
        if((temp[i] == '0') && (flag == 0)) continue;
        else flag = 1;
    }
    return (&temp[i-1]);
}

char * add(char * num, int len){
    char * temp = new char[len+1];
    int carry = 1;
    int count = len;
    for( int i = len-1; i >=0; i--){
          int x =  (num[i] - '0') + carry;
          temp[count] = (x % 10) +'0';
          carry = x / 10;
          count--;
    }
   temp[0] = carry +'0';
    int flag = 0;
    int i = 0;
    for (  i ; i <= len; i++){
        if(flag == 1) break;
        if(temp[i] == '0' && flag == 0) continue;
        flag = 1;
    }
    return (&temp[i-1]);
}

void function (char *a, char * b){
        int lena = strlen(a);
        int lenb = strlen(b);
        int x = lena/19;
        if(lena % 19 != 0) x++;
        long long unsigned int *arr = new long long unsigned int[x];

        int i = lena-1;
        int count = x-1;
        for(i ; i>=0; i= i-19){
            long long unsigned int y = 0;
            long long unsigned int p = 1;
            int z = i-19;
            if( z < 0) z = -1;
            for( int j = i; j > z; j--){
                y = y + p * (a[j] -'0');
                p = p*10;
            }
            arr[count] = y;
            count--;
        }

        char * sum = new char [lena+lenb+1];
        for( int i = 0; i< (lena+lenb+1); i++)
                sum[i] = '0';

        i = lenb-1;
        count = lena+lenb;
        for(i ; i>=0; i= i-19){
            long long unsigned int y = 0;
            long long unsigned int p = 1;
            int bit = 19;
            int z = i-19;
            if( z < 0) {
                z = -1;
                bit = i +1;
            }
            for( int j = i; j > z; j--){
                y = y + p * (b[j] -'0');
                p = p*10;
            }

            long long unsigned int prodcarry = 0;
            int sumcarry = 0;
            if( i != (lenb -1))
                    count = count -bit;
            int dummycount = count;
            long long unsigned int power = pow( 10, bit);
            for(int k = (x-1); k >=0; k--){
                long long unsigned int z = y * arr[k] + prodcarry;
                prodcarry = z / power;
                z = z%power;
                for( int q = 0; q< bit; q++){
                        int dummy = (sum[dummycount] -'0') + (z %10) + sumcarry;
                        sum[dummycount] = ((dummy %10) + '0');
                        sumcarry = dummy/10;
                        z = z/10;
                        dummycount--;
                }
            }
            while(prodcarry>0){
                int dummy = (sum[dummycount] -'0') + (prodcarry %10) + sumcarry;
                sum[dummycount] = ((dummy %10) + '0');
                sumcarry = dummy/10;
                prodcarry = prodcarry/10;
                dummycount--;
            }
            sum[dummycount] = sumcarry +'0';
        }

        int flag = 0;
        i = 0;
        for (  i ; i < (lena+lenb+1); i++){
            if(flag == 1) break;
            if(sum[i] == '0' && flag == 0) continue;
            flag = 1;
        }
        printf("%s\n", &sum[i-1]);

//        free(arr);
//        free(sum);







//    int lena = strlen(a);
//    int lenb = strlen(b);
//
//    char ** check = new char *[10];
//    check[0] = new char[lena+1];
//    check[1] = new char[lena+1];
//    for( int i = 0; i< lena; i++){
//        check[0][i] = '0';
//        check[1][i+1] = a[i];
//    }
//    check[0][lena] = '0';
//    check[1][0] = '0';
//
//    for( int i = 2; i< 10; i++){
//        check[i] = new char[lena+1];
//        int carry = 0;
//        int count = lena;
//        for ( int j = lena-1; j >= 0; j--){
//            int x = ((a[j] - '0') * i) + carry;
//            check[i][count] = (x % 10) + '0';
//            carry = x / 10;
//            count--;
//        }
//        check[i][count] = carry +'0';
//    }
//
//    char * sum = new char [lena +1+lenb];
//    for( int i = lena+lenb; i>=0; i--)
//        sum[i] = '0';
//
//    for ( int i = lenb-1 ; i >=0; i --){
//        if(b[i] == '0') continue;
//        int y = (b[i] - '0') ;
//        int carry = 0;
//        int count = lena+1+ i;
//        for( int j = lena; j >=0; j--){
//            int x = (sum[count] - '0') + (check[y][j] -'0')+ carry;
//            sum[count] = (x % 10) + '0';
//            carry = x /10;
//            count--;
//        }
//        sum[count] = carry + '0';
//    }
//    int flag = 0;
//    int i = 0;
//    for (  i ; i < (lena+lenb+1); i++){
//        if(flag == 1) break;
//        if(sum[i] == '0' && flag == 0) continue;
//        flag = 1;
//    }
//    printf("%s\n", &sum[i-1]);
////    free(check);
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--){
        char * num1 = new char [20000];
        char * num2 = new char[20001];
        scanf("%s", num1);
        int len1 = strlen(num1);
        num2 = add(num1, len1);
        int len2 = strlen(num2);
        if((num1[len1 - 1] - '0') % 2 == 0){
            num1 = divide(num1, len1);
            len1 = strlen(num1);
        }
        else{
            num2 = divide(num2, len2);
            len2 = strlen(num2);
        }
        function(num1, num2);
//        free(num1);
//        free(num2);
    }
}

