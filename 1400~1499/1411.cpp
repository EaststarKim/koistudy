#include <stdio.h>
char a[51][51];
int w[51],b[51],r[51],ans=1e4,s,t;
int main(){
    int i,j,n,m;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%s",a[i]+1);
        for(j=1;j<=m;++j)w[i]+=(a[i][j]=='W'),b[i]+=(a[i][j]=='B'),r[i]+=(a[i][j]=='R');
        t+=m-r[i];
    }
    for(i=1;i<n-1;++i){
        t+=r[i]-w[i];
        s=t;
        for(j=i+1;j<n;++j){
            s+=r[j]-b[j];
            if(ans>s)ans=s;
        }
    }
    printf("%d",ans);
    return 0;
}
