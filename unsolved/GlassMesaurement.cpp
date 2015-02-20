#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>

using namespace std;

int n;
long long unsigned int A[15];
queue <long long unsigned int> q;
int P[100001];
long long unsigned int S[100001];
long long unsigned int Amod[15];

void initialize(){
  q.push(0);
  P[0] = n-1;
  S[0] = 0;
  for( int i = 1; i < A[0]; i++){
      S[i] = A[0] * A[n-1];
      Amod[i] = A[i] % A[0];
  }
}

void sort(){
     for( int i = 0; i < n; i++){
        for( int j = i; j < n; j++){
            if( A[i] > A[j]) {
                long long unsigned int temp = A [i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
     }
}

long long unsigned int gcd( long long unsigned int a, long long unsigned int b){
    if( b == 0) return a;
    return ( gcd (b, a % b));
}

int isgcd(){
   long long unsigned int g = gcd (A[0], A[1]);
   for( int i = 2; i < n; i++){
       g = gcd (g, A[i]);
   }
   if( g == 1) return 1;
   return -1;
}

void solve(){

}

main(){
   int t;
   scanf("%d", &t);
   while ( t--){

   }

}
