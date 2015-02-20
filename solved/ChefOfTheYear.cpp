
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>
#include <map>
#include <utility>


using namespace std;

map<string, string> chefCountryMap;
map<string, int> chefCount;
map<string, int> countryCount;

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
   
    int n;
    int m;
    scanf("%d %d", &n, &m);
    
    char a[11];
    char b[11];
    
    for(int i = 0; i < n; i++){
        scanf("%s", a);
        scanf("%s", b);
        chefCountryMap.insert(map<string,string>::value_type (a, b));
        chefCount.insert(map<string,int>::value_type(a,0));
        countryCount.insert(map<string,int>::value_type(b,0));
    }
    
    for(int i = 0; i < m; i++){
        scanf("%s", a);
        chefCount.insert(map <string, int > :: value_type(a,  chefCount.find(a) -> second ++));
        countryCount.insert(map <string, int > :: value_type(chefCountryMap.find(a)->second, countryCount.find(chefCountryMap.find(a)->second)->second++));
    }
    
    int maxCount = -1;
    string maxCountry;
    for (map<string, int> :: iterator it = countryCount.begin(); it!=countryCount.end(); ++it){
        if(it->second < maxCount)
            continue;
        if (it->second > maxCount) {
            maxCount = it->second;
            maxCountry = it->first;
        }
        else {
            if(it->first.compare(maxCountry) < 0){
                maxCountry = it->first;
            }
        }
    }
    cout << maxCountry << endl;

    
    maxCount = -1;
    string maxChef;
    for (map<string, int> :: iterator it = chefCount.begin(); it!=chefCount.end(); ++it){
        if(it->second < maxCount)
            continue;
        if (it->second > maxCount) {
            maxCount = it->second;
            maxChef = it->first;
        }
        else {
            if(it->first.compare(maxChef) < 0){
                maxChef = it->first;
            }
        }
    }
    cout << maxChef;
    
       
}


