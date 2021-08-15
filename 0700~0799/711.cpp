#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int M=1e4;
int a[21][21],left[21],right[21],visit[21],tmp[21][21],n,ans;
int augment(int i){
    int j;
    for(j=1;j<=n;++j)if(!a[i][j]&&!visit[j]){
        visit[j]=1;
        if(!right[j]||augment(right[j])){
            left[i]=j;
            right[j]=i;
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
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
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
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",a[i]+j);
            tmp[i][j]=a[i][j];
        }
    }
    hungarian_method();
    for(i=1;i<=n;++i)ans+=tmp[i][left[i]];
    printf("%d",ans);
    return 0;
}
