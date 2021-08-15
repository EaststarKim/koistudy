#include <stdio.h>
#include <string.h>
#define M 10000
char A[510],B[510];
int a[510],b[510],D[510][10][510][2][4],m;
int f(int* a,int n){
    int i,j,k,l,p,ans=0;
    if(n<1)return 0;
    memset(D,0,sizeof D);
    for(j=1;j<a[0];++j){
        D[0][j][j%m][0][0]=1;
        if(n>1)D[0][j][j%m][1][0]=1;
    }
    D[0][a[0]][a[0]%m][0][1]=1;
    if(n>1)D[0][a[0]][a[0]%m][1][1]=1;
    for(i=1;i<n;++i){
        for(j=1;j<10;++j){
            D[i][j][j%m][0][0]=1;
            if(i<n-1)D[i][j][j%m][1][0]=1;
        }
    }
    for(i=0;i<n-1;++i){
        for(j=0;j<10;++j){
            for(k=0;k<m;++k){
                for(l=0;l<2;++l){
                    if(D[i][j][k][l][0]){
                        if(l){
                            for(p=0;p<j;++p)D[i+1][p][(k*10+p)%m][0][0]=(D[i+1][p][(k*10+p)%m][0][0]+D[i][j][k][1][0])%M;
                        }
                        else{
                            for(p=9;p>j;--p)D[i+1][p][(k*10+p)%m][1][0]=(D[i+1][p][(k*10+p)%m][1][0]+D[i][j][k][0][0])%M;
                        }
                    }
                    if(D[i][j][k][l][1]){
                        if(l){
                            for(p=0;p<j&&p<a[i+1];++p)D[i+1][p][(k*10+p)%m][0][0]=(D[i+1][p][(k*10+p)%m][0][0]+D[i][j][k][1][1])%M;
                            if(p<j)D[i+1][p][(k*10+p)%m][0][1]=(D[i+1][p][(k*10+p)%m][0][1]+D[i][j][k][1][1])%M;
                        }
                        else{
                            for(p=j+1;p<10&&p<a[i+1];++p)D[i+1][p][(k*10+p)%m][1][0]=(D[i+1][p][(k*10+p)%m][1][0]+D[i][j][k][0][1])%M;
                            if(p<10&&a[i+1]>j)D[i+1][p][(k*10+p)%m][1][1]=(D[i+1][p][(k*10+p)%m][1][1]+D[i][j][k][0][1])%M;
                        }
                    }
                }
            }
        }
    }
    for(j=0;j<10;++j){
        for(l=0;l<2;++l){
            for(p=0;p<2;++p)ans=(ans+D[n-1][j][0][l][p])%M;
        }
    }
    return ans;
}
int main(){
    int i,s,t;
    scanf("%s\n%s",A,B);
    scanf("%d",&m);
    s=strlen(A);
    t=strlen(B);
    for(i=0;i<s;++i)a[i]=A[i]-48;
    for(;i--;){
        --a[i];
        if(a[i]<0)a[i]+=10;
        else break;
    }
    if(!a[0]){
        --s;
        for(i=0;i<s;++i)a[i]=a[i+1];
    }
    for(i=0;i<t;++i)b[i]=B[i]-48;
    printf("%d",(f(b,t)-f(a,s)+M)%M);
    return 0;
}
