#include <stdio.h>
char a[3][110];
int main(){
    int i,j,k,tc,n,m,s,t;
    scanf("%d",&tc);
    for(;tc--;){
        scanf("%d%d",&n,&m);
        for(i=0;i<3;++i){
            scanf("%s",a[i]);
            if(a[i][0]=='s')s=(1<<i);
        }
        for(i=1;i<n;i+=3){
            t=0;
            for(j=0;j<3;++j)if(s&(1<<j)&&a[j][i]=='.'){
                for(k=-1;k<2;++k)if(0<=j+k&&j+k<3)t|=(a[j+k][i]=='.')*(1<<(j+k));
            }
            for(j=1;j<3&&i+j<n;++j){
                for(k=0;k<3;++k)if(t&(1<<k))t^=(a[k][i+j]!='.')*(1<<k);
            }
            s=t;
        }
        if(s)puts("YES");
        else puts("NO");
    }
    return 0;
}
