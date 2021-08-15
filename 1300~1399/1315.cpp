#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int nx,e;
}a[100010];
int st[5010],in[5010],ans[5010],cnt,mx;
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
int main(){
    int i,j,n,m,s,e,flag;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d",&s,&e),make_al(s,e),++in[e];
    for(m=n;m;){
        for(flag=i=1;i<=n;++i)if(!in[i]){
            for(j=st[i];j;j=a[j].nx)--in[a[j].e];
            in[i]=-1;
            ans[m--]=i;
            flag=0;
        }
        if(flag){
            puts("-1");
            return 0;
        }
    }
    for(i=n;i;--i)printf("%d ",ans[i]);
    return 0;
}
