#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

char a[1001];

struct palin {
        int post;
        int conv;
} palindrom[1001];

int len;
int mid;
int even;

char lucky[] = "lucky";

void GeneratePalin( int position, int count){
    int conv = 0;
    palindrom[count].post = position;

    char dummy[len];
    for( int i = 0; i < len; i++)
            dummy[i] = '0';

    for ( int i = position; i <= (position +4); i++){
            if( a[i] != lucky[i-position]) conv++;
            if( a[len-1-i] != lucky[i-position]) conv++;
            dummy[i] = '1';
            dummy[len-1-i] = '1';
     }

     if( (even == 0) && ((position + 4) == mid) && (a[position + 4] != 'y')) conv--;
     if( (even == 0) && (position == mid) && (a[position] != 'l')) conv--;

     for( int i = 0; i < mid; i++){
            if( dummy[i] != '1') {
                    if( a[i] != a[len-1-i]) conv++;
            }
    }
    palindrom[count].conv = conv;
 //   printf("%d %d\n", position, conv);
}

void print( int x){
    char output[len+1];
    for( int i = 0; i < mid; i++){
            if( a[i] <= a[ len-1-i]){
                    output[i] = a[i];
                    output[len-1-i] = a[i];
            }
             if( a[i] > a[ len-1-i]){
                    output[i] = a[len-1-i];
                    output[len-1-i] = a[len-1-i];
            }
    }
    if( (even == 0) && (( palindrom[x].post != mid ) || ( (palindrom[x].post + 4) != mid)))
            output[mid] = a[mid];
    for( int i = 0; i <= 4; i++){
        output[i+palindrom[x].post] = lucky[i];
        output[len-1-i-palindrom[x].post] = lucky[i];
    }
    output[len] = '\0';
    printf("%s %d\n", output, palindrom[x].conv);
}

int Lexico ( int i ,int j){

    map < int, char > m1;
    map < int, char > m2;

    for( int x = 0; x <= 4; x++){
            m1[x+palindrom[i].post] = lucky[x];
            m1[len-1-x-palindrom[i].post] = lucky[x];
    }
    for( int x = 0; x <= 4; x++){
            m2[x+palindrom[j].post] = lucky[x];
            m2[len-1-x-palindrom[j].post] = lucky[x];
    }
    for( int x = 0; x <= 4; x++){
            char min;
            if( a[x+palindrom[i].post] <= a[len-1-x-palindrom[i].post])
                    min = a[x+palindrom[i].post];
            else min = a[len-1-x-palindrom[i].post];
            if( m2.find(x+palindrom[i].post) == m2.end()){
                m2[x+palindrom[i].post] = min;
            }
            if( m2.find(len-1-x-palindrom[i].post) == m2.end()){
                m2[len-1-x-palindrom[i].post] = min;
            }
     }
      for( int x = 0; x <= 4; x++){
            char min;
            if( a[x+palindrom[j].post] <= a[len-1-x-palindrom[j].post])
                    min = a[x+palindrom[j].post];
            else min = a[len-1-x-palindrom[j].post];
            if(m1.find(x+palindrom[j].post) == m1.end()){
                m1[x+palindrom[j].post] = min;
            }
            if( m1.find(len-1-x-palindrom[j].post) == m1.end()){
                m1[len-1-x-palindrom[j].post] = min;
            }
      }

    map<int, char>::const_iterator it1;
    map<int, char>::const_iterator it2;
    for ( it1 = m1.begin(), it2 = m2.begin (); (it1 != m1.end() && it2 != m2.end()); ++it1, ++it2 ){
         if( (it1-> second)  < (it2-> second))
                return i;
         if( (it1-> second)  >  (it2-> second))
                return j;

    }
	return i;
}

void Compare ( int count){
        int minConv = palindrom[0].conv;
        for( int i  = 1; i < count; i++){
            if( palindrom[i].conv < minConv)
                    minConv = palindrom[i].conv;
        }

        int min = 0;
        for( int i = 0; i < count; i++){
            if( palindrom[i].conv == minConv){
                    min = i;
                    break;
            }
        }

        for( int i = ( min+1); i < count; i++){
            if( palindrom[i].conv == minConv){
                    min = Lexico( min, i);
            }
        }
        print(min);
}

main(){

//    freopen( "iput1.txt", "r", stdin);
 //   freopen( "output1.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while( t--){
                scanf("%s", &a[0]);
                len = strlen(a);
                mid = len/2;
                if( (len %2) == 0) even = 1;
                else even = 0;
                if( len <= 8) {
                        printf("unlucky\n");
                        continue;
                }
                int count = 0;
                for( int i = 0; i <= (mid-4-even); i++) {
                        GeneratePalin(i, count);
                        count++;
                }
                for( int i = mid; i <= (len-5); i++){
                        GeneratePalin(i, count);
                        count++;
                }
                Compare(count);
    }
}
