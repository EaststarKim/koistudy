#include <stdio.h>
#include <algorithm>
using namespace std;
int D[21][21][21],a[21],ans;
int main(){
    int i,j,k,l,n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=0;i<m;++i){
	    for(j=0;j<=t;++j){
            for(k=0;k<=n;++k){
                for(l=k+1;l<=n;++l){
                    if(j+a[l]<=t)D[i][j+a[l]][l]=max(D[i][j+a[l]][l],D[i][j][k]+1);
                    else D[i+1][a[l]][l]=max(D[i+1][a[l]][l],D[i][j][k]+1);
                }
                ans=max(ans,D[i][j][k]);
            }
	    }
    }
    printf("%d",ans);
    return 0;
}
