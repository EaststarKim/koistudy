#include <bits/stdc++.h>
using namespace std;
int b[1000010],m,p;
long long ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d",b+i);
        if(m+1<b[i]){
            if(m+2<b[i]||p){
                puts("0");
                return 0;
            }
            p=i;
        }
        m=max(m,b[i]);
    }
    if(p){
        for(i=0;i<p;++i)if(b[i]+2==b[p])break;
        ans=p-i;
    }
    else{
        m=0;
        for(i=1;i<n;++i){
            if(b[i]!=b[i-1])++ans;
            m=max(m,b[i]);
            ans+=m-(b[i]!=b[i+1]);
        }
        ++ans;
    }
    printf("%lld",ans);
    return 0;
}
