#include <stdio.h>
int c[6],x[6],n;
long long s[6],D[1000010][7],ans[6],mx;
bool cmp(long long *a,long long *b){
    int i;
    for(i=n;i;--i)if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
int main(){
    int i,j,k,m,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(i=1;i<=n;++i)scanf("%d",x+i);
    for(i=1;i<n;++i)x[i+1]*=x[i];
    scanf("%d%d",&t,&m);
    for(i=1;i<=n;++i){
        s[i]=1;
        for(j=0;j<i;++j)s[i]*=t-j;
        for(j=1;j<=i;++j)s[i]/=j;
    }
    D[0][0]=1;
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j)if(i>=c[j]&&D[i-c[j]][0]){
            if(D[i][0]<D[i-c[j]][0]+s[j]*x[j]){
                D[i][0]=D[i-c[j]][0]+s[j]*x[j];
                for(k=1;k<=n;++k)D[i][k]=D[i-c[j]][k];
                ++D[i][j];
            }
            else if(D[i][0]==D[i-c[j]][0]+s[j]*x[j]){
                ++D[i-c[j]][j];
                if(cmp(D[i],D[i-c[j]]))for(k=1;k<=n;++k)D[i][k]=D[i-c[j]][k];
                --D[i-c[j]][j];
            }
        }
    }
    for(i=1;i<=m;++i)if(D[i][0]){
        if(mx<D[i][0]){
            mx=D[i][0];
            for(j=1;j<=n;++j)ans[j]=D[i][j];
        }
        else if(mx==D[i][0]){
            if(cmp(ans,D[i]))for(j=1;j<=n;++j)ans[j]=D[i][j];
        }
    }
    for(i=1;i<=n;++i)printf("%d ",ans[i]);
    printf("\n%lld",mx-1);
    return 0;
}
