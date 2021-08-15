#include<stdio.h>
#define M 1000000009
char a[100010],b[100010];
long long C[26][100010],D[26][100010],ans;
int main(){
    int i,j,n;
    scanf("%d\n%s\n%s",&n,a+1,b+1);
    for(i=0;i<26;++i)for(j=1;j<=n;++j)C[i][j]=C[i][j-1]+(b[j]==i+65)*j;
    for(i=0;i<26;++i)for(j=n;j>0;--j)D[i][j]=D[i][j+1]+(b[j]==i+65)*(n-j+1);
    for(i=1;i<=n;++i)ans=((ans+C[a[i]-65][i]*(n-i+1)%M)%M+D[a[i]-65][i+1]*i%M)%M;
    printf("%d",ans);
    return 0;
}
