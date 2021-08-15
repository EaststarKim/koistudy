#include <stdio.h>
#include <algorithm>
using namespace std;
int p[][4]={100,70,40,0,70,50,30,0,40,30,20};
int D[12][12],m[12][12][1<<13],n,x,y,z;
char t[12];
int f(int r,int c,int s){
    if(r==n)return 0;
    if(c==n)return f(r+1,0,s);
    if(!m[r][c][s]){
        if(!(s&y)){
            if(c+1<n&&!(s&x))m[r][c][s]=max(m[r][c][s],f(r,c+2,(s<<2)%z)+p[D[r][c]][D[r][c+1]]);
            if(r+1<n&&!(s&1))m[r][c][s]=max(m[r][c][s],f(r,c+1,((s|1)<<1)%z)+p[D[r][c]][D[r+1][c]]);
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
        scanf("%s",t);
        for(j=0;j<n;++j)D[i][j]=(t[j]=='F'? 3:t[j]-'A');
    }
    printf("%d",f(0,0,0));
    return 0;
}
