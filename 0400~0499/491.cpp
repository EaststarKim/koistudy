#include <stdio.h>
int s[800010];
long long t[800010],ans;
void rnk(int k){for(;k;k/=2)++t[k];}
long long pls(int l,int r){
    long long s=0;
    while(l<=r){
        if(l%2)mx+=t[l++];
        if(r%2==0)mx+=t[r--];
        l/=2,r/=2;
    }
    return s;
}
int main(){
	int i,n,x,h;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;++i){
        scanf("%d",&h);
        s[i]=s[i-1]+(h<x?-1:1);
    }
    for(i=n;i>0;--i){
        rnk(s[i]+3*MX);
        ans+=pls(s[i-1]+3*MX,4*MX);
    }
    printf("%lld",ans);
    return 0;
}
