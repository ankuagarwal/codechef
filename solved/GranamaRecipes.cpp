#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int GR[26];
int GS[26];
int CR[26];
int CS[26];

void initialize(){
    for(int i = 0; i <= 26; i++){
        GR[i] = 0;
        GS[i] = 0;
        CR[i] = 0;
        CS[i] = 0;
    }
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    int t;
    scanf ("%d", &t);
    while (t--){
        initialize();
        char r[1001];
        char s[1001];
        scanf("%s", r);
        scanf("%s", s);
        
        int l = strlen(r);
        for(int i = 0 ; i < l; i++){
            GR[r[i]-'a']++;
            CR[r[i]-'a'] = 1;
        }
        
        l = strlen(s);
        for (int i = 0; i < l; i++){
            GS[s[i]-'a']++;
            CS[s[i]-'a'] = 1;
        }
        
        bool isGranny = true;
        for(int i = 0; i < 26; i++){
            if(GR[i] - GS[i] != 0)
                isGranny = false;
        }
        
        bool isChef = true;
        for(int i = 0 ; i < 26; i++){
            if(CR[i] - CS[i] != 0)
                isChef = false;
        }
        
        if(isGranny && isChef)
                printf("YES\n");
        if(isGranny && !isChef)
                printf("NO\n");
        if(!isGranny && isChef)
                printf("NO\n");
        if(!isGranny && !isChef)
                printf("YES\n");
        
        
    }
}
