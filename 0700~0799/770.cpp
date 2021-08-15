#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
}p[1010];
int n,w,m[1010][1010];
int d(int a, int b){
    return abs(p[a].x-p[b].x)+abs(p[a].y-p[b].y);
}
int f(int a,int b){
    int t=max(a,b)+1;
    if(a==w+1||b==w+1)return 0;
    if(!m[a][b]){
        m[a][b]=1<<25;
        m[a][b]=min(m[a][b],min(f(t,b)+d(a,t),f(a,t)+d(b,t)));
    }
    return m[a][b];
}
int main()
{
    int i,a=0,b=1,t;
    scanf("%d%d",&n,&w);
    p[0].x=p[0].y=1;
    p[1].x=p[1].y=n;
    for(i=2;i<=w+1;i++)scanf("%d%d",&p[i].x,&p[i].y);
    printf("%d\n",f(0,1));
    for(i=2;i<=w+1;i++){
        t=max(a,b)+1;
        if(m[t][b]+d(a,t)>m[a][t]+d(b,t))puts("2"),b=t;
        else puts("1"),a=t;
    }
    return 0;
}
