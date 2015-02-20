#include<stdio.h>
#include<math.h>

struct value{
    int zero;
    int one;
    int two;
    int updateFlag;
} values[400000];

int limit;

void printStat(){
        for(int i = 1; i <= limit; i++){
                printf("%d %d %d %d\n", values[i].zero, values[i].one, values[i].two, values[i].updateFlag);
        }
        printf("\n");
}

void initialize ( int node, int start, int end ) {
      if (start == end){
            values[node].zero = 1;
      }
      else {
            initialize ( 2 * node, start, (start + end) / 2);
            initialize(2 * node + 1, (start + end) / 2 + 1, end);
            values[node].one = values[2 * node + 1].one + values[2* node].one;
            values[node].two = values[2 * node + 1].two + values[2* node].two;
            values[node].zero = values[2 * node + 1].zero + values[2* node].zero;
      }
}

void rotate(int node){
    int temp = values[node].zero;
    values[node].zero = values[node].two;
    values[node].two = values[node].one;
    values[node].one = temp;
}

void update ( int node, int start, int end, int i, int j ) {
    if (i > end || j < start){
       return;
    }
    else if( start >= i && end <= j){
        values[node].updateFlag++;
        if(values[node].updateFlag == 3){
                values[node].updateFlag = 0;
        }
        return;
    }
    else {
        if(values[node].updateFlag != 0){
            values[2*node].updateFlag += values[node].updateFlag;
            values[2*node].updateFlag = values[2*node].updateFlag % 3;
            values[2*node+1].updateFlag += values[node].updateFlag;
            values[2*node+1].updateFlag = values[2*node+1].updateFlag % 3;
            values[node].updateFlag = 0;
        }
        update ( 2 * node, start, (start + end) / 2, i, j);
        update (2 * node + 1, (start + end) / 2 + 1, end, i , j);

        int cl,cr;
        cl = (values[2*node].updateFlag == 0) ? values[2*node].zero :(values[2*node].updateFlag == 1 ? values[2*node].two : values[2*node].one);
        cr = (values[2*node+1].updateFlag == 0) ? values[2*node+1].zero :(values[2*node+1].updateFlag == 1 ? values[2*node+1].two : values[2*node+1].one);
        values[node].zero = cl+cr;
        cl = (values[2*node].updateFlag == 0) ? values[2*node].one :(values[2*node].updateFlag == 1 ? values[2*node].zero : values[2*node].two);
        cr = (values[2*node+1].updateFlag == 0) ? values[2*node+1].one :(values[2*node+1].updateFlag == 1 ? values[2*node+1].zero : values[2*node+1].two);
        values[node].one = cl+cr;
        cl = (values[2*node].updateFlag == 0) ? values[2*node].two :(values[2*node].updateFlag == 1 ? values[2*node].one : values[2*node].zero);
        cr = (values[2*node+1].updateFlag == 0) ? values[2*node+1].two :(values[2*node+1].updateFlag == 1 ? values[2*node+1].one : values[2*node+1].zero);
        values[node].two = cl+cr;
    }
}

int query ( int node, int start, int end, int i, int j) {
      if (i > end || j < start)
          return 0;
      if( start >= i && end <= j){
            if(values[node].updateFlag == 0){
                return values[node].zero;
            }
            else if(values[node].updateFlag == 1){
                return values[node].two;
            }
            else{
                return values[node].one;
            }
    }
    else {
          if( values[node].updateFlag != 0){
                values[2*node].updateFlag += values[node].updateFlag;
                values[2*node].updateFlag = values[2*node].updateFlag % 3;
                values[2*node+1].updateFlag += values[node].updateFlag;
                values[2*node+1].updateFlag = values[2*node+1].updateFlag % 3;
                if ( (values[node].updateFlag) == 1)
                        rotate(node);
                else if ((values[node].updateFlag) == 2) {
                        rotate(node);
                        rotate(node);
                }
                values[node].updateFlag = 0;
            }
            int c1 = query ( 2 * node, start, (start + end) / 2, i, j);
            int c2 = query(2 * node + 1, (start + end) / 2 + 1, end, i , j);
            return( c1+ c2);
      }
}

main(){
     //   freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

        int n, q;
        scanf("%d %d", &n, &q);
        limit = 2* pow(2, ((log10(n)/log10(2))+1));
        for( int i = 1; i <= limit; i++){
                values[i].one = 0;
                values[i].two = 0;
                values[i].zero = 0;
                values[i].updateFlag = 0;
        }
        initialize(1, 0, n-1);

        //printStat();

        int flag, start, end;
        for( int i = 1; i <= q; i++){
                scanf("%d %d %d", &flag, &start, &end);
                if (flag == 0){
                        update(1, 0, n-1, start, end);
                }
                else{
                        int count = query(1, 0 , n-1, start, end);
                        printf("%d\n", count);
                }

                //printStat();
        }
}
