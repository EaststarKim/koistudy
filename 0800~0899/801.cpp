#include <stdio.h>
#include <string.h>
using namespace std;
long long D[100010];
char a[100010],p[110][1010];
int l[110],pi[110][1010],t[100010][110],m;
void ff(int k){
    int i=0,j=-1;
    pi[k][0]=-1;
    while(i<l[k]){
        if(j<0||p[k][i]==p[k][j])++i,++j,pi[k][i]=j;
        else j=pi[k][j];
    }
}
int kmp(int k){
    int i=0,j=0;
    while(i<m){
        if(j<0||a[i]==p[k][j])++i,++j;
        else j=pi[k][j];
        if(j>=l[k])t[i-1][++t[i-1][0]]=k;
    }
    return 0;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%s",p[i]);
        l[i]=strlen(p[i]);
        ff(i);
    }
    scanf("%s",a);
    m=strlen(a);
    for(i=1;i<=n;++i)kmp(i);
    D[0]=1;
    for(i=0;i<m;++i){
        for(j=1;j<=t[i][0];++j)D[i+1]=(D[i+1]+D[i-l[t[i][j]]+1])%1000000007;
    }
    printf("%d",D[m]);
    return 0;
}
