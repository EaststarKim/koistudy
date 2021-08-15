#include <stdio.h>
int a[9],t[10],n,ans=1e9;
void f(int p,int s){
    int i,m;
    if(s>n){
        int chk[9]={};
        for(i=0,m=p;m--&&!chk[i];i=(i+a[i])%p)chk[i]=1;
        if(m<0&&!i)ans=s;
        return;
    }
    for(i=1;i<10&&s*10+i<ans;++i)if(!t[i])a[p]=i,t[i]=1,f(p+1,s*10+i),t[i]=0;
}
int main(){
    scanf("%d",&n);
    f(0,0);
    printf("%d",ans);
    return 0;
}
