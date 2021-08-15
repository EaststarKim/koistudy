#include<stdio.h>   
int m(int a,int b){if(a>b)return a;return b;}   
int w[2002],i,j,n,D[2001][2001],s[2002];   
int main(){   
    scanf("%d",&n);   
    for(i=1;i<=n;i++){   
        scanf("%d",&w[i]);   
        s[i]=s[i-1]+w[i];}   
    for(i=1;i<=n;i++)D[i][i]=w[i];   
    for(i=1;i<n;i++){   
        for(j=1;j<=n-i;j++){   
            D[j][j+i]=m(D[j+1][j+i],D[j][j+i-1])+s[j+i]-s[j-1];}}   
    printf("%d\n",D[1][n]);   
} 