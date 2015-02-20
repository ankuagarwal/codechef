#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <utility>

using namespace std;

char a[25001];
char b[25001];

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%s %s", a, b);
        int lenA = strlen(a);
        int lenB = strlen(b);
        int indexA = 0;
        int indexB = 0;
        
        while (indexA < lenA && indexB < lenB ){
            if(a[indexA] == b[indexB])
                indexB++;
            indexA++;
        }
        if(indexA == lenA && indexB < lenB){
            indexA = 0;
            indexB = 0;
            while (indexA < lenA && indexB < lenB ){
                if(a[indexA] == b[indexB])
                    indexA++;
                indexB++;
            }
            if(indexB == lenB && indexA < lenA){
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
        }
        else {
            printf("YES\n");
        }
    }
}