#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int D[5010][5010]={{1}},s,t;
int main(){
    int i,j,m,n,l,k,a,b,ans=-1;
    scanf("%d%d%d%d",&m,&n,&l,&k);
    for(;k--;){
        scanf("%d%d",&a,&b);
        for(i=s;i>=0;--i){
            for(j=t;j>=0;--j)if(D[i][j])D[i+a][j+b]=1;
        }
        s+=a,t+=b;
    }
    a=gcd(m,n);
    m/=a,n/=a;
    for(i=1;m*i<=s&&n*i<=t;++i)if(D[m*i][n*i]&&(m+n)*i>=l){
        ans=(m+n)*i;
        break;
    }
    printf("%d",ans);
    return 0;
}
