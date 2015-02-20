#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <queue>

using namespace std;

char Passwords[10000000];
int Matrix[350][350];
long long unsigned totalPrime[10000000];

struct cord{
    int i;
    int j;
} ;

void generatePrimeNumbers(){
    int * prime = new int [31623];
    int * primenumber = new int [3402];
    long count = 0;
    for( long i = 2 ; i < 31623; i++ ){
        if( prime[i] == 1)
            continue;
        prime[i] = -1;
        primenumber[count] = i;
        count++;
        for( long j = i + i ; j < 31623; j = j + i )
            prime[j] = 1;
    }
    
    long m = 1;
    long n = 10000000;
    long diff = n - m + 1;
    int * check = new int [diff];
    int xyz = 0;
    long p = sqrt(n);
    for ( long k = 0; k < count; k++  ){
        if( primenumber[k] >= p) break;
        long start = 0;
        if ( primenumber[k] >= m){
            xyz++;
            Passwords[primenumber[k]] = 'P';
            start = primenumber[k] - m;
        }
        else{
            long rem = m % primenumber[k];
            if( rem != 0)
                start = primenumber[k] - ( m % primenumber[k] );
        }
        for ( long j = start ; j < diff; j = j + primenumber[k])
            check[j] = 1;
    }
    
   long i = 0;
    if( m == 1) i ++;
    for( i ; i < diff; i ++){
        if( check[i] == 0){
            Passwords[i+m] = 'P';
            xyz++;
        }
    }
}

void generatePasswords(){
    for(int i = 0; i < 10000000; i++){
        if(Passwords[i] != 'P'){
            if(i % 2 == 0)
                Passwords[i] = 'E';
            else
                Passwords[i] = 'O';
        }
    }
}

void initializeMatrix(){
    for(int i = 0; i < 350; i++){
        for(int j = 0; j < 350; j++){
            Matrix[i][j] = 0;
        }
    }
}

void generatePrimeCount(){
    totalPrime[0] = 0;
    for(int i = 1; i < 10000000; i++){
        if(Passwords[i] == 'P')
            totalPrime[i] = totalPrime[i-1] + 1;
        else
            totalPrime[i] = totalPrime[i-1];
    }
        
}

void initialize(){
    generatePrimeNumbers();
    generatePasswords();
    generatePrimeCount();
    
}

void print(int n){
    for(int i = 0 ; i< n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", Matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

long long unsigned  solvePrime(int i){
    return (totalPrime[i]-1);
}

void bfs(int i, int j, int n){
  queue <cord> q;     
    cord c;
    c.i = i;
    c.j = j;
    q.push(c);
    
    while ( ! q.empty()){
        cord top = q.front();
        q.pop();
        if( ((top.i + 1) < n) && (Matrix[top.i+1][top.j] != -1) && (Passwords[Matrix[top.i+1][top.j]] == Passwords[Matrix[top.i][top.j]])){
            cord toPush;
            toPush.i = top.i+1;
            toPush.j = top.j;
            q.push(toPush);
        }
        if( ((top.j+ 1) < n) && (Matrix[top.i][top.j+1] != -1) && (Passwords[Matrix[top.i][top.j+1]] == Passwords[Matrix[top.i][top.j]])){
            cord toPush;
            toPush.i = top.i;
            toPush.j = top.j+1;
            q.push(toPush);
        }
        if( ((top.i-1) >= 0) && (Matrix[top.i-1][top.j] != -1) && (Passwords[Matrix[top.i-1][top.j]] == Passwords[Matrix[top.i][top.j]])){
            cord toPush;
            toPush.i = top.i-1;
            toPush.j = top.j;
            q.push(toPush);
        }
        if( ((top.j-1) >= 0) && (Matrix[top.i][top.j-1] != -1) && (Passwords[Matrix[top.i][top.j-1]] == Passwords[Matrix[top.i][top.j]])){
            cord toPush;
            toPush.i = top.i;
            toPush.j = top.j-1;
            q.push(toPush);
        } 
        Matrix[top.i][top.j] = -1;
    }
    
}

long long unsigned solveNotPrime(int i, int j, int n){
    int value = Matrix[i][j];
    int wrong = value /2;
    if(value % 2 != 0)
        wrong = wrong + 2;
    bfs(i, j, n);
    return wrong;
}

void solve(int n){
    long long unsigned  ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Matrix[i][j] != -1){
                if(Passwords[Matrix[i][j]] == 'P'){
                    ans = ans + solvePrime(Matrix[i][j]);
                }
                else{
                    ans = ans + solveNotPrime(i, j, n);
                }
            }
        }
    }
    printf("%llu\n", ans);
}

int main(){
    
    freopen("/Users/ankit/Desktop/myProject/myProject/input.txt", "r", stdin);
    freopen("/Users/ankit/Desktop/myProject/myProject/output.txt", "w", stdout);
    
    initialize();
    
    int t;
    scanf("%d", &t);
    while (t--){
        initializeMatrix();
        int n;
        scanf("%d", &n);
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &Matrix[i][j]);
            }
        }
        solve(n);
    }
}