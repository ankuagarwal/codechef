#include<iostream>
#include<stdio.h>
#include<string.h>

int priority(char a){
        if(a == '/') return 4;
        if(a == '*') return 3;
        if(a == '-') return 2;
        if(a == '+') return 1;
        return 0;
}


char* transformation(char exp[]){
        int len = strlen(exp);
        int count = 0;
        char newexp[400];
        for(int i = 0 ; i< len ; i++){
                if(exp[i] == '('){
                        if( ((i-1) >=0)  && (i +2) < len)
                            if(priority(exp[i-1]) != 0  &&  priority(exp[i +2]) != 0 && priority(exp[i-1]) >= priority(exp[i+2])){
                                        newexp[count] = exp[i];
                                        count ++;
                            }

                        continue;
                }
                 else  if(exp[i] == ')'){
                                if( ((i+1) < len)  && (i -2) >=0)
                                        if(priority(exp[i+1]) != 0  &&  priority(exp[i -2]) != 0  && priority(exp[i+1]) >= priority(exp[i-2])){
                                                newexp[count] = exp[i];
                                                count ++;
                                        }
                                else{
                                        int c1 = 0;
                                        int c2 = 0;
                                        for(int j = count  - 1 ;  j >= 0 ; j -- ){
                                                if(newexp[j] == '(')
                                                        c1++;
                                                if(newexp[j] == ')')
                                                        c2++;
                                        }
                                        if(c1 != c2 && c1 > 0){
                                                newexp[count] = exp[i];
                                                count ++;
                                        }
                                }
                                continue;
                }
                 else  {
                         newexp[count] = exp[i];
                         count ++;
                 }
        }
        newexp[count] = '\0';
        return newexp;
}

main(){
        int t;
        scanf("%d",&t);
        char ** exp = new char *[t];
        for(int i = 0 ; i < t; i++){
                exp[i] = new char[400];
                scanf("%s",exp[i]);
       }
        for(int i = 0 ; i < t; i++){
                printf("%s\n", transformation(exp[i]));
        }
}
