#include <stdio.h>
#include <string.h>
char c[100000];
int a[100000],flag,s;
int f(int a){
    int i;
    if(!a)return 1;
    for(i=0;a;a/=10,++i);
    return i;
}
int main(){
    int i,n,d,m,t,in,tm;
    scanf("%d%d",&n,&d);
    if(n%d==0)printf("%d.0\n",n/d);
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
            in++;
        }
        for(i=0;i<in;++i){
            printf("%c",c[i]);
            s++;
            if(s%76==0)s=0,printf("\n");
        }
        if(s%76)printf("\n");
    }
    return 0;
}
