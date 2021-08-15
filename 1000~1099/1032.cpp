#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int g,s,h;
    bool operator<(const data&r)const{
        return g*s*h<r.g*r.s*r.h;
    }
}a[3510];
int D[3510],mx;
int main()
{
    int i,j,n,k,p=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].g,&a[i].s,&a[i].h);
    sort(a,a+n+1);
    for(i=1;i<=n;++i)if(a[i].h<=k){
        for(j=0;j<i;++j)if(a[j].g<=a[i].g&&a[j].s<=a[i].s)D[i]=max(D[i],D[j]+1);
        mx=max(mx,D[i]);
    }
    printf("%d",mx);
    return 0;
}
