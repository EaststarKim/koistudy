#include <stdio.h>
#include <algorithm>
int a[1010],ans;
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        if(a[i]==i)continue;
        for(j=1;j<=n;++j){
            if(a[j]==i)break;
        }
        if(j==n){
            std::reverse(a+i,a+n+1);
            ++ans;
        }
        else{
            std::reverse(a+j,a+n+1);
            std::reverse(a+i,a+n+1);
            ans+=2;
        }
    }
    printf("%d",ans);
    return 0;
}
