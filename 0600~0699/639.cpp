#include <stdio.h>
#include <string.h>
char c[130];
int automata(int t,int p){
    if(c[p]=='F'){
        if(t<2)t=t+1;
        else if(t==5||t==8)t=1;
        else if(t==7)t=8;
        else if(t!=2)t=9;
    }
    else if(c[p]=='M'){
        if(t==2||t==4||t==6)t=t+1;
        else if(t!=5)t=9;
    }
    else if(c[p]=='C'){
        if(t==1||t==6)t=6;
        else if(t==3)t=4;
        else t=9;
    }
    else t=9;
    return t;
}
int main()
{
    int i,n,t=0;
    scanf("%s",c);
    n=strlen(c);
    for(i=0;i<n;++i)t=automata(t,i);
    if(t==5||t==8)puts("REGEND DEER!");
    else puts("NORMAL DEER");
    return 0;
}
