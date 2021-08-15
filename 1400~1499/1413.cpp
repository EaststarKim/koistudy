#include <stdio.h>
char a[3010][3010];
int w[3010],b[3010],r[3010],ans=1e7,s,t;
int main(){
    int i,j,n,m;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%s",a[i]+1);
        for(j=1;j<=m;++j)w[i]+=(a[i][j]=='W'),b[i]+=(a[i][j]=='B');
        r[i]=m-w[i]-b[i];
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
