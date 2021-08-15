#include<stdio.h>      
int min(int a,int b){if(a<b)return a;return b;}      
int n,w[1001][1001],D[2][1001][1001],i,j,r[2][1001][1001],a;      
int main(){      
    scanf("%d",&n);      
    for(i=1;i<=n;i++){      
        for(j=1;j<=n;j++){      
            scanf("%d",&w[i][j]);a=w[i][j];      
            while(a>0&&!(a&1))a/=2,r[0][i][j]++;      
            while(a>0&&a%5==0)a/=5,r[1][i][j]++;      
            D[0][i][j]=D[1][i][j]=1e9;      
        }      
    }      
    for(i=1;i<=n;i++){      
        for(j=1;j<=n;j++){      
            if(i==1&&j==1){D[0][1][1]=r[0][1][1],D[1][1][1]=r[1][1][1];continue;}      
            if(w[i][j]==0)continue;      
            if(i>1)D[0][i][j]=D[0][i-1][j]+r[0][i][j],D[1][i][j]=D[1][i-1][j]+r[1][i][j];      
            if(j>1&&D[0][i][j]>D[0][i][j-1]+r[0][i][j])D[0][i][j]=D[0][i][j-1]+r[0][i][j];      
            if(j>1&&D[1][i][j]>D[1][i][j-1]+r[1][i][j])D[1][i][j]=D[1][i][j-1]+r[1][i][j];      
        }      
    }      
    printf("%d\n",min(D[0][n][n],D[1][n][n]));      
}  