#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

char B[26];

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
  
    int t;
    scanf("%d", &t);
    
    char c;
    c = getchar();
    for(int i = 0; i < 26; i++){
        c = getchar();
        B[i] = c;
    }
    c = getchar();
    
    
   
    for(int i = 0; i < t; i++){
        c = getchar();
        while (c != EOF && c != '\n'){
            
            if('a' <= c && c <= 'z')
                printf("%c",  B[c-'a']);
        
            else if ('A' <= c && c <= 'Z')
                printf("%c", B[c + 32 - 'a'] - 32);
        
            else if(c == '_')
                printf(" ");
            
            else
                printf("%c", c);
        
            c = getchar();
        }
        printf("\n");
    
    }
    
}