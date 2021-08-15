#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MX=1e9;
struct data{
    int x,y;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}s[1010];
double D[1010][1010];
double dis(int n,int m){
    return sqrt((s[n].x-s[m].x)*(s[n].x-s[m].x)+(s[n].y-s[m].y)*(s[n].y-s[m].y));
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&s[i].x,&s[i].y);
    sort(s+1,s+n+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)D[i][j]=MX;
    }
    D[1][1]=0;
    for(i=2;i<=n;++i){
        for(j=1;j<i;++j){
            if(D[j][i-1]==MX)continue;
            D[j][i]=min(D[j][i],D[j][i-1]+dis(i-1,i));
            D[i-1][i]=min(D[i-1][i],D[j][i-1]+dis(j,i));
        }
    }
    for(i=1;i<n;++i){
        if(D[i][n]==MX)continue;
        D[n][n]=min(D[n][n],D[i][n]+dis(i,n));
    }
    printf("%.0f",D[n][n]);
    return 0;
}
