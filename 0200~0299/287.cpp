#include <stdio.h>
#include <algorithm>
using namespace std;
int a[60][60],c[30],ans=1e8,ai;
int main(){
    int i,j,k,p,s,e;
    char t;
    scanf("%d",&p);
    for(i=1;i<59;++i){
        for(j=1;j<59;++j)a[i][j]=1e8;
    }
    for(i=1;i<=p;++i){
        scanf(" %c",&t);
        s=t-64;
        if(t<97)c[s]=1;
        scanf(" %c",&t);
        e=t-64;
        if(t<97)c[e]=1;
        scanf(" %d",&k);
        a[s][e]=min(a[s][e],k);
        a[e][s]=min(a[e][s],k);
    }
    for(k=1;k<59;++k){
        for(i=1;i<59;++i)if(a[i][k]<1e8){
            for(j=1;j<59;++j)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    for(i=1;i<26;++i)if(c[i]&&ans>a[i][26])ans=a[i][26],ai=i;
    printf("%c %d",ai+64,ans);
    return 0;
}
