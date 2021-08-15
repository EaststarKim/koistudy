#include <stdio.h>
int a[31][31],r[31][31],c[31][31];
int ans[31],ai[31],aj[31],ak[31],al[31];
int main(){
    int i,j,k,l,m,n,q,s,t;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",a[i]+j);
            r[i][j]=a[i][j]+r[i][j-1];
            c[i][j]=a[i][j]+c[i-1][j];
        }
    }
    for(m=1;m<=q;++m){
        ans[m]=-1e5;
        for(i=1;i<n-1;++i){
            for(j=1;j<n-1;++j){
                for(k=i+2;k<=n;++k){
                    s=c[k][j]-c[i-1][j];
                    for(l=j+2;l<=n;++l){
                        t=s+r[i][l]-r[i][j]+r[k][l]-r[k][j]+c[k-1][l]-c[i][l];
                        if(ans[m]<t)ans[m]=t,ai[m]=i,aj[m]=j,ak[m]=k,al[m]=l;
                    }
                }
            }
        }
        if(ans[m]==-1e5){
            puts("0");
            return 0;
        }
        for(i=ai[m];i<=ak[m];++i)a[i][aj[m]]=a[i][al[m]]=-1e6;
        for(i=aj[m];i<=al[m];++i)a[ai[m]][i]=a[ak[m]][i]=-1e6;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)r[i][j]=a[i][j]+r[i][j-1],c[i][j]=a[i][j]+c[i-1][j];
        }
    }
    for(i=1;i<=q;++i)printf("%d %d %d %d %d\n",ans[i],ai[i],aj[i],ak[i],al[i]);
    return 0;
}
