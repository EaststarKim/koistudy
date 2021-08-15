#include <stdio.h>
#include <algorithm>
using namespace std;
int a[300010],D[300010];
int p[]={4,2,1,2,4};
int main(){
    int i,j,n,l,g,t,s;
    scanf("%d%d%d",&l,&n,&g);
    for(i=1;i<=n;++i){
        scanf("%d%d",&t,&s);
        a[t]=s;
    }
    for(i=1;i<=l;++i){
        s=0;
        for(j=-2;j<3;++j)if(i+j>0)s+=a[i+j]/p[j+2];
        D[i]=max(D[i-1],(i>g?D[i-g]:0)+s);
    }
    printf("%d",D[l]);
    return 0;
}
