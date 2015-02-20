#include <iostream>
#include <cstdio>
using namespace std;

int countSetBits(unsigned int num){
    int ret = 0;
    while(num){
        num = num & (num-1);
        ret++;
    }
    return ret;
}

int main(){
    //freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    int n,a,b;
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        int n1 = countSetBits(a);
        int n2 = countSetBits(b);
        if(n1 < n2){
            n1 = n1+ n2;
            n2 = n1 - n2;
            n1 = n1 - n2;
        }
        int no = min(n1,n-n2) + min(n2, n-n1);
        int nz = n-no;
        int x = (1 << n) -1;
        int y = (1 << nz)- 1;

        printf("%d\n", x^y);
    }

}
