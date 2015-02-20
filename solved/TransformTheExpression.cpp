#include<iostream>
#include<stdio.h>
#include<cstring>

char stack[400];

void transformation(char exp[]){
        int len = strlen(exp);
        int stackcount = 0;
        int postfixcount = 0;
        char *postfix = new char[len];

        for(int i = 0 ; i< len ; i++){
                if(exp[i]  == '^' || exp[i]  == '/' ||exp[i]  == '*' || exp[i]  == '+' || exp[i]  == '-'){
                            stack[stackcount] = exp[i];
                            stackcount++;
                            continue;
                }
                if(exp[i] == ')'){
                            stackcount --;
                            postfix[postfixcount] = stack[stackcount];
                            postfixcount++;
                            continue;
                }
                if(exp[i] != '('){
                            postfix[postfixcount] = exp[i];
                            postfixcount++;
                            continue;
                }
        }
        printf("%s\n",postfix);
}

main(){
    int tcase;
    scanf("%d",&tcase);

    for(int i = 0 ; i < tcase; i++){
            char *exp = new char[400];
            scanf("%s",exp);
            transformation(exp);
    }
}
