#include <stdio.h>
int a[100010],st[100010];
long long s,p;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        while(p>0&&st[p-1]<=a[i])--p,s+=p;
        st[p++]=a[i];
    }
    s+=p*(p-1)/2;
    p=0;
    for(i=n;i>0;--i){
        while(p>0&&st[p-1]<a[i])--p,s+=p;
        st[p++]=a[i];
    }
    s+=p*(p-1)/2;
    printf("%lld",s);
    return 0;
}
