#include <stdio.h>
int a[1010][11][11],w[1010],h[1010];
void add(int a[11][11],int b[11][11],int n,int m,int t){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)printf("%d ",a[i][j]+b[i][j]*t);
        puts("");
    }
}
void mul(int a[11][11],int b[11][11],int n,int m,int l){
    int i,j,k,s;
    for(i=1;i<=n;++i){
        for(j=1;j<=l;++j){
            s=0;
            for(k=1;k<=m;++k)s+=a[i][k]*b[k][j];
            printf("%d ",s);
        }
        puts("");
    }
}
int main(){
    int i,j,k,n,q;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",w+i,h+i);
        for(j=1;j<=w[i];++j){
            for(k=1;k<=h[i];++k)scanf("%d",a[i][j]+k);
        }
    }
    scanf("%d",&q);
    for(;q--;){
        scanf("%d %c %d",&i,&c,&j);
        if(c=='*'){
            if(h[i]==w[j])mul(a[i],a[j],w[i],h[i],h[j]);
            else puts("impossible!");
        }
        else{
            if(w[i]==w[j]&&h[i]==h[j])add(a[i],a[j],w[i],h[i],c=='+'?1:-1);
            else puts("impossible!");
        }
    }
    return 0;
}
