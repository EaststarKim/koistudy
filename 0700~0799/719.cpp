#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[14][14],m[14][14][1<<15],n,x,y,z;
int f(int r,int c,int s){
    if(r==n)return 0;
    if(c==n)return f(r+1,0,s);
    if(!m[r][c][s]){
        if(!(s&y)){
            if(c+1<n&&!(s&x))m[r][c][s]=max(m[r][c][s],f(r,c+2,(s<<2)%z)+100-abs(a[r][c]-a[r][c+1]));
            if(r+1<n&&!(s&1))m[r][c][s]=max(m[r][c][s],f(r,c+1,((s|1)<<1)%z)+100-abs(a[r][c]-a[r+1][c]));
            m[r][c][s]=max(m[r][c][s],f(r,c+1,(s<<1)%z));
        }
        else m[r][c][s]=max(m[r][c][s],f(r,c+1,(s<<1)%z));
    }
    return m[r][c][s];
}
int main()
{
    int i,j;
    scanf("%d",&n);
    y=1<<n;
    x=y>>1;
    z=y<<1;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)scanf("%d",a[i]+j);
    }
    printf("%d",f(0,0,0));
    return 0;
}
