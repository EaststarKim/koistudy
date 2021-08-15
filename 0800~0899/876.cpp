#include <stdio.h>
int a[1010],chk[1010],ans;
void seek(int p){
    if(!p){
        ++ans;
        return;
    }
    if(chk[p])return;
    chk[p]=1;
    seek(a[p]);
    chk[p]=0;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)seek(i);
    printf("%d",ans);
    return 0;
}
