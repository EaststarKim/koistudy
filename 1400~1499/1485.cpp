#include <stdio.h>
#include <algorithm>
using namespace std;
int a[262145],e[262145][59],mn=60,mx;
bool d[262145][59];
int main(){
    int i,j,n,ans;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i),mn=min(mn,a[i]),mx=max(mx,a[i]),d[i][a[i]]=1,e[i][a[i]]=i;
    for(i=mn;i<59;++i){
        for(j=0;j<n;++j)if(d[j][i-1]&&d[e[j][i-1]+1][i-1])d[j][i]=1,e[j][i]=e[e[j][i-1]+1][i-1],ans=i;
        if(i>mx&&ans<i)break;
    }
    printf("%d",ans);
    return 0;
}
