#include <stdio.h>
#include <string.h>
struct data{
    int v,n,s[6],w[6];
}a[6];
int chk[360];
int main(){
    int i,j,k,t,s;
    for(i=1;i<6;++i){
        scanf("%d%d",&a[i].v,&a[i].n);
        for(j=1;j<=a[i].n;++j)scanf("%d%d",&a[i].s[j],&a[i].w[j]);
    }
    for(t=0;t<360;++t){
        memset(chk,0,sizeof chk);
        for(i=1;i<6;++i){
            s=a[i].v*t%360;
            for(j=1;j<=a[i].n;++j){
                for(k=0;k<=a[i].w[j];++k)++chk[(a[i].s[j]+k+s)%360];
            }
        }
        for(i=0;i<360;++i)if(chk[i]>4){
            printf("%d",t);
            return 0;
        }
    }
    puts("none");
    return 0;
}
