#include <stdio.h>
int a[300010],b[300010],ans;
int main(){
    int i,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]=1;
    scanf("%d",&s);
    for(i=1;i<=n;++i)if(a[i]<=s)ans+=b[s-a[i]];
    printf("%d",ans/2);
    return 0;
}
