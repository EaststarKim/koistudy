#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x1,y1,x2,y2,c;
    data(){}
    data(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
}t[1010];
int ans[2510];
int f(data a,int p,int k){
    int s=0;
    if(a.x2<=a.x1||a.y2<=a.y1)return 0;
    if(p==k)return (a.x2-a.x1)*(a.y2-a.y1);
    data b=t[p];
    if(a.x2<b.x1||b.x2<a.x1||a.y2<b.y1||b.y2<a.y1)return f(a,p-1,k);
    s+=f(data(a.x1,a.y1,b.x1,a.y2),p-1,k);
    s+=f(data(b.x2,a.y1,a.x2,a.y2),p-1,k);
    s+=f(data(max(a.x1,b.x1),b.y2,min(a.x2,b.x2),a.y2),p-1,k);
    s+=f(data(max(a.x1,b.x1),a.y1,min(a.x2,b.x2),b.y1),p-1,k);
    return s;
}
int main(){
    int i,n;
    scanf("%d%d%d",&t[0].x2,&t[0].y2,&n);
    t[0].c=1;
    for(i=1;i<=n;++i)scanf("%d%d%d%d%d",&t[i].x1,&t[i].y1,&t[i].x2,&t[i].y2,&t[i].c);
    for(i=n;i>=0;--i)ans[t[i].c]+=f(t[i],n,i);
    for(i=1;i<2501;++i)if(ans[i])printf("%d %d\n",i,ans[i]);
    return 0;
}
