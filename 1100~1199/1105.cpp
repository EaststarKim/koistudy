#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],p,s,t,ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n+1;++i){
        if(a[i-1]<a[i])++t;
        else{
            if((t>1&&a[p]+1<a[p+2])||(s>1&&a[p+1]-1>a[p-1]))ans=max(ans,s+t);
            else ans=max(ans,max(s,t)+1);
            p=i-1,s=t,t=1;
        }
    }
    printf("%d",ans);
    return 0;
}
