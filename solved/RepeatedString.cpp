#include <iostream>
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#define pii pair<int,int>
#define f1 first
#define s2 second
#define dbg(x) cout<<#x<<" = "<<x<<'\n'
using namespace std;


inline bool leq(int a1, int a2,   int b1, int b2) {
    return(a1 < b1 || a1 == b1 && a2 <= b2);
}

inline bool leq(int a1, int a2, int a3,   int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
}

static void radixPass (int* a, int* b, int* r, int n, int K) {
    int* c = new int[K + 1];
    for (int i = 0;  i <= K;  i++) c[i] = 0;
    for (int i = 0;  i < n;  i++) c[r[a[i]]]++;
    for (int i = 0, sum = 0;  i <= K;  i++) {
        int t = c[i];  c[i] = sum;  sum += t;
    }
    for (int i = 0;  i < n;  i++) b[c[r[a[i]]]++] = a[i];
        delete [] c;
}

void suffixArray(int* s, int* SA, int n, int K) {
    int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
    int* s12  = new int[n02 + 3];
    s12[n02]= s12[n02+1]= s12[n02+2]=0;
    int* SA12 = new int[n02 + 3];
    SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
    int* s0   = new int[n0];
    int* SA0  = new int[n0];

    for (int i=0, j=0;  i < n+(n0-n1);  i++)
            if (i%3 != 0)
                    s12[j++] = i;

    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);

    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0;  i < n02;  i++) {
            if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
                    name++;  c0 = s[SA12[i]];  c1 = s[SA12[i]+1];  c2 = s[SA12[i]+2];
            }
            if (SA12[i] % 3 == 1) {
                    s12[SA12[i]/3] = name;
            }
            else {
                    s12[SA12[i]/3 + n0] = name;
            }
    }

    if (name < n02) {
            suffixArray(s12, SA12, n02, name);
            for (int i = 0;  i < n02;  i++)
                    s12[SA12[i]] = i + 1;
    }
    else
            for (int i = 0;  i < n02;  i++)
                    SA12[s12[i] - 1] = i;

    for (int i=0, j=0;  i < n02;  i++)
            if (SA12[i] < n0)
                    s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);

    for (int p=0,  t=n0-n1,  k=0;  k < n;  k++) {
        int i = (SA12[t] <  n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2) ;
        int j = SA0[p];
        if (SA12[t] < n0 ? leq(s[i],  s12[SA12[t] + n0], s[j], s12[j/3]) :  leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0])){
            SA[k] = i;  t++;
            if (t == n02) {
                for (k++;  p < n0;  p++, k++) SA[k] = SA0[p];
            }
        }
        else {
            SA[k] = j;
            p++;
            if (p == n0)  {
                    for (k++;  t < n02;  t++, k++) SA[k] = (SA12[t] <  n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2) ;
            }
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

main(){
  //  freopen("in.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    char a[100010];
    int s[100010], SA[100010];
    pii streaks[50000];
    int l, h;
    scanf("%d%d", &l, &h);
    while(l+h){
        memset(a,0,sizeof(a));
            scanf("%s", &a[0]);
     
            int len = strlen (a);
            for (int i = 0;  i < len;  i++) {
                    s[i] =a[i] - 'a' +1;
                    SA[i] = 0;
            }
            streaks[0]=pii(0,0);
            s[len] = s[len+1] = s[len+2] = SA[len] = SA[len+1] = SA[len+2] = 0;
            suffixArray(s, SA, len, 26);
            int mx=1,lmx=1,nostr=1;
            for(int i=1;i<len;i++){
                bool f=true;
                if((len-SA[i])<l){
                    f=false;
                }
                for(int j=0;j<l;j++){
                    if((len-SA[i-1])<l || a[SA[i]+j]!=a[SA[i-1]+j]){
                        f=false;
                        lmx=1;
                        break;
                    }
                }
               if(f){
                    lmx++;
                }
                 if(mx==lmx){
                    streaks[nostr].f1=i-lmx+1;
                    streaks[nostr].s2=i;
                    nostr++;
                }
                if(lmx>mx){
                    mx=lmx;
                    streaks[0].f1=streaks[nostr-1].f1;
                    streaks[0].s2=i;
                    nostr=1;
                }
            }
            lmx=l;
            for(int i=l;i<h && nostr;i++){
                for(int j=0;j<nostr;j++){
                    int beg=streaks[j].f1+1,end=streaks[j].s2;
                    for(int k=beg;k<=end;k++){
                        if(a[SA[k]+i]!=a[SA[k-1]+i]){           
                            nostr--;
                            streaks[j]=streaks[nostr];
                            j--;
                            break;
                        }
                    }
                }
                if(nostr){
                    lmx=i+1;
                }
            }
           printf("%d %d\n",mx,lmx);
           scanf("%d%d", &l, &h);
    }
}

