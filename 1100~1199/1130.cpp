#include <stdio.h>
int a[23],chk[25],ans,t;
int main(){
    int n,s;
    scanf("%d",&n);
    s=n+1;
    chk[1]=1;
    for(;;){
        if(t>n-3)++ans,--t;
        if(t<0)break;
        s-=a[t],chk[a[t]]=0;
        int &k=++a[t];
        for(;k<n;++k)if(!chk[k]&&s%k==0)break;
        if(k==n)a[t]=0,--t;
        else chk[k]=1,++t,s+=k;
    }
    printf("%d",ans);
    return 0;
}
