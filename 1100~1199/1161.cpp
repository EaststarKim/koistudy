#include <stdio.h>
int a[110],s[110],chk[110][110],ans;
int f(int l,int r){
    if(chk[l][r])return chk[l][r];
    int x=f(l+1,r),y=f(l,r-1);
    if(x<=y)chk[l][r]=s[r]-s[l-1]-x;
    else chk[l][r]=s[r]-s[l-1]-y;
    return chk[l][r];
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),s[i]=s[i-1]+a[i],chk[i][i]=a[i];
    ans=f(1,n);
    printf("%d %d",ans,s[n]-ans);
    return 0;
}
