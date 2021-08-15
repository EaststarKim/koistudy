#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int M=1e5;
int p[7],x[7],a[51][51],left[51],right[51],visit[51],tmp[51][51],n,ans;
int augment(int i){
    int j;
    for(j=1;j<=n;++j)if(!a[i][j]&&!visit[j]){
        visit[j]=1;
        if(!right[j]||augment(right[j])){
            left[i]=j,right[j]=i;
            return 1;
        }
    }
    return 0;
}
void hungarian_method(){
    int i,j,cnt=0,mn;
    for(i=1;i<=n;++i){
        mn=M;
        for(j=1;j<=n;++j)mn=min(mn,a[i][j]);
        for(j=1;j<=n;++j)a[i][j]-=mn;
    }
    for(i=1;i<=n;++i){
        mn=M;
        for(j=1;j<=n;++j)mn=min(mn,a[j][i]);
        for(j=1;j<=n;++j)a[j][i]-=mn;
    }
    while(1){
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;++i)if(!left[i]&&augment(i)){
            ++cnt;break;
        }
        if(cnt==n)break;
        if(i<=n)continue;
        mn=M;
        for(i=1;i<=n;++i)if(!left[i]||visit[left[i]]){
            for(j=1;j<=n;++j)if(!visit[j])mn=min(mn,a[i][j]);
        }
        for(i=1;i<=n;++i)if(!left[i]||visit[left[i]]){
            for(j=1;j<=n;++j)a[i][j]-=mn;
        }
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)if(visit[j])a[i][j]+=mn;
        }
    }
}
int main(){
    int i,j,k,t;
    scanf("%d",&n);
    for(i=1;i<7;++i)scanf("%d",p+i);
    for(i=1;i<=n;++i){
        for(t=j=1;j<7;++j){
            scanf("%d",x+j);
            for(k=1;k<=p[j];++k)tmp[i][t]=a[i][t++]=x[j];
        }
    }
    hungarian_method();
    for(i=1;i<=n;++i)ans+=tmp[i][left[i]];
    printf("%d",ans);
    return 0;
}
