#include <stdio.h>
int a[21][2],n,w,mx;
void back(int i,int s,int p){
    if(i>n){
        if(mx<p)mx=p;
        return;
    }
    if(s+a[i][0]<=w)back(i+1,s+a[i][0],p+a[i][1]);
    back(i+1,s,p);
}
int main(){
    int i;
    scanf("%d%d",&n,&w);
    for(i=1;i<=n;++i)scanf("%d%d",a[i],a[i]+1);
    back(1,0,0);
    printf("%d",mx);
    return 0;
}
