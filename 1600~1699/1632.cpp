#include <stdio.h>
char c[60];
int main(){
    int i,s=0;
    scanf("%s",c);
    for(i=0;c[i];++i){
        if(c[i]=='(')++s;
        else --s;
        if(s<0)break;
    }
    puts(s?"NO":"YES");
    return 0;
}
