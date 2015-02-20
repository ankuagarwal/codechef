#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

struct books{
    char name[16];
    int excercise;
    int booksOnTop;
};

stack <books> B;

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    books b;
    scanf("%d", &b.excercise);
    scanf("%s", b.name);
    b.booksOnTop = 0;
    
    B.push(b);
    
    int x;
    char dummy[16];
    for(int i = 1; i < n; i++){
        scanf("%d", &x);
        if(x == 0){
            scanf("%s", dummy);
            continue;
        }
        if(x == -1){
            b = B.top();
            B.pop();
            printf("%d %s\n", b.booksOnTop, b.name);
        }
        else {
            if(B.size() == 0){
                b.excercise = x;
                scanf("%s", b.name);
                b.booksOnTop = 0;
                B.push(b);
            }
            else {
                if(x <= B.top().excercise){
                    b.excercise = x;
                    scanf("%s", b.name);
                    b.booksOnTop = 0;
                    B.push(b);
                }
                else {
                    scanf("%s", dummy);
                    B.top().booksOnTop++;
                }
            }
         }
    }
}