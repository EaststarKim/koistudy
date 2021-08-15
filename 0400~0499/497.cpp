#include <stdio.h>
#include <algorithm>
using namespace std;
int p[5][20010],ans[20010];
int cmp(int a,int b){
     int i,s=0;
     for(i=0;i<5;++i)s+=p[i][a]>p[i][b];
     return s>2;
}
int main(){
    int i,j,n,t;
    scanf("%d",&n);
    for(i=0;i<5;++i){
        for(j=1;j<=n;++j){
            scanf("%d",&t);
            p[i][t]=ans[j]=j;
        }
    }
    sort(ans+1,ans+n+1,cmp);
    for(i=n;i>0;--i)printf("%d\n",ans[i]);
    return 0;
}
