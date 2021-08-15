#include <stdio.h>
#include <string.h>
char c[5000];
int a[5000],flag,s;
int f(int a){
    int i;
    if(!a)return 1;
    for(i=0;a;a/=10,++i);
    return i;
}
int main(){
    int i,n,d,m,t,in,tm;
    scanf("%d%d",&n,&d);
    if(n%d==0)printf("%d.(0)\n",n/d);
    else{
        t=n/d;
        in=f(t);
        for(i=in-1;i>=0;--i){
            tm=t%10;
            c[i]=tm+48;
            t/=10;
        }
        c[in++]='.';
        memset(a,-1,sizeof a);
        while(1){
            tm=n%d;
            if(!tm)break;
            if(a[tm]!=-1){
                flag=1;
                break;
            }
            t=tm*10/d;
            a[tm]=in;
            c[in++]=t+48;
            n=tm*10;
        }
        if(flag){
            m=a[tm];
            for(i=in-1;i>=m;--i)c[i+1]=c[i];
            c[m]='(',c[++in]=')';
        }
        else c[in++]='(',c[in++]='0',c[in]=')';
        puts(c);
    }
    return 0;
}
