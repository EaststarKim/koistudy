#include <stdio.h>
#include <algorithm>
using namespace std;
char a[110][110];
int D[210][110][110],chk[210][110][110],x[210],y[210],n;
void path(int i,int j,int k){
    if(i<3)return;
    int p=D[i-1][j-1][k-1],q=D[i-1][j-1][k],r=D[i-1][j][k-1],s=D[i-1][j][k],m,t;
    m=max(p,max(q,max(r,s)));
    if(m==p)t=1;
    else if(m==q)t=2;
    else if(m==r)t=3;
    else if(m==s)t=4;
    x[++n]=t/3+1,y[n]=t+(t<3)*2;
    path(i-1,j-(t<3),k-(t&1));
}
int main(){
    int i,j,k,w,h,s,t;
    scanf("%d%d",&w,&h);
    for(i=h;i;--i){
        scanf("%s",a[i]+1);
        reverse(a[i]+1,a[i]+w+1);
    }
    for(i=2;i<=w+h;++i){
        for(j=0;j<=h;++j){
            for(k=0;k<=w;++k)D[i][j][k]=-1;
        }
    }
    D[2][1][1]=(a[1][1]=='*');
    for(i=3;i<=w+h;++i){
        for(j=1;j<i;++j)if(j<=h&&i-j<=w&&a[j][i-j]!='#'){
            for(k=1;k<i;++k)if(k<=h&&i-k<=w&&a[k][i-k]!='#'){
                s=0,t=-1;
                if(a[j][i-j]=='*')++s;
                if(a[k][i-k]=='*')++s;
                if(j==k&&s>1)s=1;
                t=max(D[i-1][j-1][k-1],max(D[i-1][j-1][k],max(D[i-1][j][k-1],D[i-1][j][k])));
                if(t>=0)D[i][j][k]=t+s,chk[i][j][k]=1;
            }
        }
    }
    printf("%d\n",D[w+h][h][h]);
    path(w+h,h,h);
    for(i=1;i<=n;++i)printf("%d ",x[i]);
    for(;--i;)printf("%d ",y[i]);
    return 0;
}
