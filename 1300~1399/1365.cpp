#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int i,j,n,m,t,l,r,mid,ans;
    long long s;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d",&n,&m);
        l=1,r=n;
        while(l<=r){
            mid=(l+r)/2;
            s=n;
            for(i=1;i*i<=mid&&s>0;++i)s-=min(m,mid/i);
            j=i-1;
            for(i=1;i*i<mid&&i<=m&&s>0;++i)s-=mid/i-j;
            if(s>0)l=mid+1;
            else r=mid-1,ans=mid;
        }
        printf("%d\n",ans);
    }
    return 0;
}
