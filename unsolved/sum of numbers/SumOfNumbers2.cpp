#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

void function (char * a, char * b){

        int lena = strlen(a);
        int lenb = strlen(b);

        int newlena = lena/9;
        if(lena % 9 != 0) newlena++;
        long long unsigned int *arra = new long long unsigned int[newlena];
        int i = lena-1;
        int count = newlena-1;
        for(i ; i>=0; i = i-9){
            long long unsigned int y = 0;
            long long unsigned int p = 1;
            int z = i - 9;
            if( z < 0) z = -1;
            for( int j = i; j > z; j--){
                y = y + p * (a[j] -'0');
                p = p*10;
            }
            arra[count] = y;
            count--;
        }

        int newlenb= lenb/9;
        if(lenb % 9 != 0) newlenb++;
        long long unsigned int *arrb = new long long unsigned int[newlenb];
        i = lenb-1;
        count = newlenb-1;
        for(i ; i>=0; i = i-9){
            long long unsigned int y = 0;
            long long unsigned int p = 1;
            int z = i - 9;
            if( z < 0) z = -1;
            for( int j = i; j > z; j--){
                y = y + p * (b[j] -'0');
                p = p*10;
            }
            arrb[count] = y;
            count--;
        }

        int len = newlena+newlenb;
        long long unsigned int *ans = new long long unsigned int[len];
        for( int i = 0; i< len; i++)
                ans[i] = 0;

        long long unsigned int power = pow( 10, 9);
        for( int i = (newlenb-1); i>=0; i--){
                int countans = (len-1) - ( newlenb - 1 - i);
                long long unsigned int prodcarry = 0;
                long long unsigned int sumcarry = 0;
                for( int j = (newlena-1); j >=0; j--){
                    long long unsigned int y = (arrb[i] * arra[j]) + prodcarry;
                    prodcarry = y / power;
                    y = y % power;
                    long long unsigned int x = ans[countans] + y + sumcarry;
                    ans[countans] = x % power;
                    sumcarry = x/power;
                    countans--;
                }
                long long unsigned int x = ans[countans] + prodcarry + sumcarry;
                ans[countans] = x % power;
        }
        i = 0;
        for( int j = 0; j < len; j++){
            if( ans[j] == 0) continue;
            printf("%llu", ans[j]);
            i = j +1;
            break;
        }
        for( i ; i < len; i++){
            int digits = log10(ans[i]) +1;
            int extra = 9-digits;
            for(int j = 1; j <= extra; j++)
                    printf("%c", '0');
            printf("%llu", ans[i]);
        }
        printf("\n");
//        delete(arra);
//        delete(arrb);
//        delete(ans);
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
//        delete(num1);
//        delete(num2);
    }
}
