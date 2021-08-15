#include <stdio.h>
#include <algorithm>
using namespace std;
int D[31][31][51];
int f(int n,int m,int k){
    if(n*m<k)return 1e6;
    if(n*m==k||!k)return 0;
    int &s=D[n][m][k];
    if(s)return s;
    s=1e6;
    int i,j;
    for(i=1;i<n;++i){
        for(j=0;j<k;++j)s=min(s,f(i,m,j)+f(n-i,m,k-j)+m*m);
    }
    for(i=1;i<m;++i){
        for(j=0;j<k;++j)s=min(s,f(n,i,j)+f(n,m-i,k-j)+n*n);
    }
    return s;
}
int main(){
    int t,n,m,k;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",f(n,m,k));
    }
    return 0;
}
