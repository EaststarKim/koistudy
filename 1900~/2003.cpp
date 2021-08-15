#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int x[20010],y[20010],r[2010],c[2010],s[2010],t[2010],ans=1e9;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<2001;++i)r[i]=c[i]=1e9;
    r[1000]=c[1000]=0;
    x[0]=y[0]=1e3;
    for(i=1;i<=n;++i){
        scanf("%d%d",x+i,y+i);
        x[i]+=1e3,y[i]+=1e3;
        for(j=0;j<2001;++j)s[j]=t[j]=1e9;
        for(j=0;j<2001;++j)s[j]=min(s[j],r[j]+abs(x[i]-x[i-1])),t[x[i-1]]=min(t[x[i-1]],r[j]+abs(y[i]-j));
        for(j=0;j<2001;++j)s[y[i-1]]=min(s[y[i-1]],c[j]+abs(x[i]-j)),t[j]=min(t[j],c[j]+abs(y[i]-y[i-1]));
        for(j=0;j<2001;++j)r[j]=s[j],c[j]=t[j];
    }
    for(j=0;j<2001;++j)ans=min(ans,min(r[j],c[j]));
    printf("%d",ans);
    return 0;
}
