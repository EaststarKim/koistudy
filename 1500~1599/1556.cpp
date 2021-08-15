#include <stdio.h>
#include <algorithm>
using namespace std;
int p[4000010],t,ans;
long long s[4000010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=2;i<=n;++i)if(!p[i]){
        s[++t]=s[t-1]+i;
        for(j=i*2;j<=n;j+=i)p[j]=1;
    }
    for(i=1;i<=t;++i){
        j=lower_bound(s,s+i,s[i]-n)-s;
        if(s[i]-s[j]==n)++ans;
    }
    printf("%d",ans);
    return 0;
}
