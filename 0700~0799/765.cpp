#include <stdio.h>
#include <stdlib.h>
struct data{
    int x,y;
}a[11];
int chk[11],ans=1e6,n;
void back(int p,int cnt,int s){
    int i;
    if(s>=ans)return;
    if(cnt==n){
        s+=abs(a[p].x)+abs(a[p].y);
        if(ans>s)ans=s;
        return;
    }
    for(i=1;i<=n;++i)if(!chk[i]){
        chk[i]=1;
        back(i,cnt+1,s+abs(a[i].x-a[p].x)+abs(a[i].y-a[p].y));
        chk[i]=0;
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    back(0,0,0);
    printf("%d",ans);
    return 0;
}
