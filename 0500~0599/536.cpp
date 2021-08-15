#include <stdio.h>
#define min(a,b)a<b?a:b
int a[16],t[15],n,ans;
int f(int i,int p){
    if(i>n)return 0;
    if(a[i]==p)return f(i+1,p);
    else if(a[i]==2)return t[n-i]*2+1+f(i+1,4-p);
    else return t[n-i]*4+2+f(i+1,p);
}
int main(){
    int i,j,k,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<4;++i){
        scanf("%d",&j);
        for(;j--;)scanf("%d",&k),a[k]=i;
    }
    for(i=1;i<n;++i)t[i]=t[i-1]*3+1;
    ans=min(f(1,1),f(1,3));
    if(ans>m)ans=-1;
    printf("%d",ans);
    return 0;
}
