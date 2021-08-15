#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<vector<int>,int> M;
int a[100010][30],ans;
int main(){
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        for(j=0;j<m;++j)a[i][j]=a[i-1][j]+!!(k&(1<<j));
    }
    vector<int> v;
    for(i=0;i<m;++i)v.push_back(0);
    M[v]=1;
    for(i=1;i<=n;++i){
        k=1e9;
        v.clear();
        for(j=0;j<m;++j)k=min(k,a[i][j]);
        for(j=0;j<m;++j)v.push_back(a[i][j]-k);
        j=M[v];
        if(!j)M[v]=j=i+1;
        ans=max(ans,i+1-j);
    }
    printf("%d",ans);
    return 0;
}
