#include<iostream>
#include<cstdio>
#include<cstdlib>

struct node{
        int leftSum;
        int rightSum;
        node * left;
        node * right;
};

int function ( long long unsigned int num, int digit, node * &temp){
    if( digit == 0) return 0;
    int sum = 0;
    if (( (1<<(digit-1)) & num) == 0){
            temp -> leftSum++;
            if( temp -> left == NULL){
                temp -> left = new node;
                temp->left -> leftSum = 0;
                temp->left -> rightSum = 0;
                temp->left -> left = NULL;
                temp->left -> right = NULL;
            }
            sum = temp -> rightSum;
            sum += function( num , digit-1, temp->left);
    }
    else{
        temp -> rightSum++;
        if( temp -> right == NULL){
                temp->right=new node;
                temp->right -> leftSum = 0;
                temp->right -> rightSum = 0;
                temp->right -> left = NULL;
                temp->right -> right = NULL;
            }
        sum += function(num , digit-1,  temp->right);
    }
    return sum;
}

main(){
    int n;
    scanf("%d", &n);
    long long unsigned int x;
    int sum = 0;
    node *root = new node();
    root -> leftSum = 0;
    root -> rightSum = 0;
    root -> left = NULL;
    root -> right = NULL;
    for( int  i = 0; i < n ; i++){
            scanf("%llu", &x);
            sum += function (x, 64, root);
    }
    printf("%d\n", sum);
}
