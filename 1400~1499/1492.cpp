#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define M 1000000007
int a[510],b[510],l[1010];
long long D[510][1010],comb;
int inv[510]={0,1};
vector<int> v;
int main(){
    int i,j,k,n,m,r;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",a+i,b+i);
        v.push_back(a[i]);
        v.push_back(b[i]+1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(i=1;i<=n;++i){
        a[i]=upper_bound(v.begin(),v.end(),a[i])-v.begin();
        b[i]=upper_bound(v.begin(),v.end(),b[i])-v.begin();
    }
    m=v.size();
    for(i=1;i<m;++i)l[i]=v[i]-v[i-1];
    for(i=0;i<m;++i)D[0][i]=1;
    for(i=2;i<=n;++i)inv[i]=(long long)(M-M/i)*inv[M%i]%M;
    for(i=1;i<=n;++i){
        for(j=a[i];j<=b[i];++j){
            D[i][j]=D[i-1][j-1]*l[j]%M;
            r=1,comb=l[j]-1;
            for(k=i;--k;)if(a[k]<=j&&j<=b[k]){
                comb=comb*inv[++r]%M*(r+l[j]-2)%M;
                D[i][j]=(D[i][j]+D[k-1][j-1]*comb)%M;
            }
        }
        D[i][0]=1;
        for(j=1;j<m;++j)D[i][j]=(D[i][j]+D[i-1][j]+D[i][j-1]-D[i-1][j-1]+M)%M;
    }
    printf("%lld",(D[n][m-1]-1+M)%M);
    return 0;
}
