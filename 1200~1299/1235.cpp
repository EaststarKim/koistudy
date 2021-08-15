#include <stdio.h>
int a[21][21],n,m;
double D[50][730];
double f(int d,int p){
    int i,j,k,l;
    double s,mx=0;
    if(!d){
        if(!p)return 0.5;
        if(p>0)return 1.0;
        return 0.0;
    }
    if(D[d][p+360]>-0.5)return D[d][p+360];
    for(i=2;i<n;++i)
        for(j=2;j<m;++j){
            s=0;
            for(k=-1;k<2;++k)for(l=-1;l<2;++l)s+=1-f(d-1,-p-a[i+k][j+l]);
            s/=9;
            if(mx<s)mx=s;
        }
    return D[d][p+360]=mx;
}
int main(){
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%1d",a[i]+j);
    }
    for(i=0;i<41;++i){
        for(j=0;j<721;++j)D[i][j]=-1.0;
    }
    printf("%lf",1-f(k*2,0));
    return 0;
}
