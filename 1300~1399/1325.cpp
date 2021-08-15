#include <stdio.h>
char a[300];
int main(){
    int i,h=0,s=0;
    fgets(a,sizeof a,stdin);
    for(i=0;a[i];++i){
        if(a[i]==':'&&a[i+1]=='-'){
            if(a[i+2]==')')++h;
            if(a[i+2]=='(')++s;
        }
    }
    if(!h&&!s)puts("none");
    else if(h>s)puts("happy");
    else if(h<s)puts("sad");
    else puts("unsure");
    return 0;
}
