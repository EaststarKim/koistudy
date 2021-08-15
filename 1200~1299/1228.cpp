#include <stdio.h>
int a[310],D[100010],r[100010],s;
int main(){
    int i,j,n,t,p;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
    t=s/2+1;
    D[0]=1,r[0]=s;
    for(i=1;i<=n;++i){
        for(j=t-1;j>=0;--j)if(D[j]&&r[j]>j+a[i]){
            p=r[j]<t+a[i]?r[j]:t+a[i];
            if(r[j+a[i]]<p)r[j+a[i]]=p;
            D[j+a[i]]=1;
        }
    }
    for(i=s;i>=t;--i)if(D[i])break;
    printf("%d",i);
    return 0;
}
