#include<stdio.h>
#include<stdlib.h>

int matrix[3][3] = {0, 1, 2, 1, 2, 0, 2, 0 , 1};

main(){

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        int t;
        scanf("%d ", &t);
        while(t--){
            int boards;
            int r, c;
            int ans = 0;
            scanf("%d", &boards);
            for( int i = 0; i < boards; i++){
                    scanf("%d %d", &r, &c);
                    r = (r-1)%3;
                    c = (c-1)%3;
		    ans = ans ^ matrix[r][c];
                 //   ans = (ans & ~matrix[r][c]) | ((~ans & matrix[r][c]));
            }
            if(ans == 0)
                    printf("Football\n");
            else
                    printf("MasterChef\n");
        }
}
