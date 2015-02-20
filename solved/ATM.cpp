#include<iostream>

using namespace std;

main(){
    int x ;
    float y ;
    cin>>x >> y;
    cout.precision(2);
    if(x % 5 != 0){
        cout<<fixed<<y;
    }
    else{
        if((float) (x+0.5) > y)
           cout<<fixed<<y;
        else
           cout<<fixed<<(y-x-0.5);
    }
}
