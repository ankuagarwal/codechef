#include<stdio.h>
#include<math.h>

struct point{
    int x;
    int y;
}points[100000];

void merge(int p, int q, int r){
    int n1= q-p+1;
    int n2 = r- q;

    struct point l1[n1+2];
    struct point l2[n2+2];

    for( int i = 1; i <= n1; i++){
            l1[i].x = points[p+i-1].x;
            l1[i].y = points[p+i-1].y;
    }
    l1[n1+1].x = 10001;
    l1[n1+1].y = 10001;

    for( int i = 1; i <= n2; i++){
            l2[i].x = points[q+i].x;
            l2[i].y = points[q+i].y;
    }
    l2[n2+1].x = 10001;
    l2[n2+1].y = 10001;

    int i = 1;
    int j = 1;
    for(int k = p ; k <= r; k++){
        if(l1[i].x < l2[j].x){
            points[k].x = l1[i].x;
            points[k].y = l1[i].y;
            i++;
        }
        else if(l1[i].x > l2[j].x){
            points[k].x = l2[j].x;
            points[k].y = l2[j].y;
            j++;
        }
        else if( l1[i].x == l2[j].x){
            if(l1[i].y >= l2[j].y){
                points[k].x = l1[i].x;
                points[k].y = l1[i].y;
                i++;
            }
            else{
                points[k].x = l2[j].x;
                points[k].y = l2[j].y;
                j++;
            }
        }
    }
}

void mergesort(int p , int r){
    if( p < r){
        int q = (p+ r)/2;
        mergesort(p, q);
        mergesort(q+1, r);
        merge(p,q,r);
    }
}

double calDist(struct point p1, struct point p2){
    int a= p2.x -p1.x;
    int b = p2.y-p1.y;
    if( b < 0)  b = 0-b;
    if( a == 0) return b;
    if( b == 0) return a;
    a = pow(a, 2);
    b = pow(b, 2);
    return (sqrt(a+b));
}

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d", &points[i].x);
            scanf("%d", &points[i].y);
        }

        mergesort(0, n-1);
        double dist = 0.0;
        for( int i = 0 ; i < n ; i++){
            if( i != n-1)
                dist = dist + calDist(points[i], points[i+1]);
        }
        printf("%.2f\n", dist);
    }
}

