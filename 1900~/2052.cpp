#include <stdio.h>
int a[100010],q[100010],t[100010],ans[100010],f,r;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
    q[0]=i;
    for(;--i;) {
        while(f<r&&t[q[f+1]]<=a[q[f+1]-1]-a[i-1])++f;
        ans[i]=ans[q[f]]+1;
        t[i]=a[q[f]-1]-a[i-1];
        q[++r]=i;
        while(f<r&&t[q[r-1]]-a[q[r-1]-1]>t[q[r]]-a[q[r]-1])q[r-1]=q[r--];
    }
    printf("%d",ans[1]);
    return 0;
}
