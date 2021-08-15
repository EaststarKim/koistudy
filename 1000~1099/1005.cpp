#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char f[5010],m[5010];
int D[8][5010],ans;
int main()
{
    int i,n;
    scanf("%s%s",f,m);
    n=strlen(f);
    for(i=0;i<n;++i){
        D[0][i]=1;
        if(f[i]=='G'||m[i]=='G'){
            if(D[1][i]||D[0][i])D[1][i+1]=max(D[1][i+1],max(D[1][i],D[0][i])+1);
        }
        if(f[i]=='A'||m[i]=='A'){
            if(D[1][i]||D[2][i])D[2][i+1]=max(D[2][i+1],max(D[1][i],D[2][i])+1);
            if(D[4][i]||D[5][i])D[5][i+1]=max(D[5][i+1],max(D[4][i],D[5][i])+1);
            if(D[6][i]||D[7][i])D[7][i+1]=max(D[7][i+1],max(D[6][i],D[7][i])+1);
        }
        if(f[i]=='T'||m[i]=='T'){
            if(D[2][i])D[3][i+1]=max(D[3][i+1],D[2][i]+1);
            if(D[3][i]||D[4][i])D[4][i+1]=max(D[4][i+1],max(D[3][i],D[4][i])+1);
        }
        if(f[i]=='C'||m[i]=='C'){
            if(D[5][i]||D[6][i])D[6][i+1]=max(D[6][i+1],max(D[5][i],D[6][i])+1);
        }
    }
    for(i=1;i<=n;++i)ans=max(ans,D[7][i]-1);
    printf("%d",ans);
    return 0;
}
