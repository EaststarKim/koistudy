#include <stdio.h>
#include <algorithm>
using namespace std;
int D[1010][50010]={{1}},s,mn=1e5;
int main(){
    int i,j,n,r,k;
    scanf("%d%d%d",&n,&r,&k);
    for(i=0;i<n;++i){
        scanf("%d",&k);
        for(j=0;j<=s;++j)if(D[i][j]){
            D[i+1][j+k]=min(D[i+1][j+k]?D[i+1][j+k]:mn,D[i][j]+k);
            if(j>=r)D[i+1][j-r]=min(D[i+1][j-r]?D[i+1][j-r]:mn,D[i][j]);
        }
        s+=k;
    }
    for(i=0;i<=s;++i)if(D[n][i])mn=min(mn,D[n][i]);
    printf("%d",mn-1);
    return 0;
}
