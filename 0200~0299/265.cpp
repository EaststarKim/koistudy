#include <stdio.h>
struct data{
    int a[3];
}q[8010],p,n;
int a[3],chk[21][21][21],f,r=1;
int main(){
    int i,j;
    scanf("%d%d%d",a,a+1,a+2);
    q[1].a[2]=a[2];
    chk[0][0][a[2]]=1;
    while(f<r){
        p=q[++f];
        for(i=0;i<3;++i){
            for(j=0;j<3;++j)if(i!=j){
                n=p;
                if(n.a[i]<a[j]-n.a[j])n.a[j]+=n.a[i],n.a[i]=0;
                else n.a[i]-=a[j]-n.a[j],n.a[j]=a[j];
                if(!chk[n.a[0]][n.a[1]][n.a[2]])chk[n.a[0]][n.a[1]][n.a[2]]=1,q[++r]=n;
            }
        }
    }
    for(i=0;i<=a[2];++i)if(chk[0][a[2]-i][i])printf("%d ",i);
    return 0;
}
