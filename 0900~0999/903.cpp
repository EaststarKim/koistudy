#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> m;
int p[5][20010],ans[20010];
int cmp(int a,int b){
     int i,s=0;
     for(i=0;i<5;++i)s+=p[i][m[a]]>p[i][m[b]];
     return s>2;
}
int main(){
    int i,j,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        m[t]=i;
        p[0][i]=i;
        ans[i]=t;
    }
    for(i=1;i<5;++i){
        for(j=1;j<=n;++j){
            scanf("%d",&t);
            p[i][m[t]]=j;
        }
    }
    sort(ans+1,ans+n+1,cmp);
    for(i=n;i;--i)printf("%d\n",ans[i]);
    return 0;
}
