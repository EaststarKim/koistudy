#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,z;
}a[30010];
bool x1(data a,data b){return a.x<b.x;}
bool x2(data a,data b){return a.x>b.x;}
bool y1(data a,data b){return a.y<b.y;}
bool y2(data a,data b){return a.y>b.y;}
bool z1(data a,data b){return a.z<b.z;}
bool z2(data a,data b){return a.z>b.z;}
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    scanf("%d",&k);
    if((k-1)/2==0){
        if(k%2)sort(a+1,a+n+1,x1);
        else sort(a+1,a+n+1,x2);
    }
    else if((k-1)/2==1){
        if(k%2)sort(a+1,a+n+1,y1);
        else sort(a+1,a+n+1,y2);
    }
    else{
        if(k%2)sort(a+1,a+n+1,z1);
        else sort(a+1,a+n+1,z2);
    }
    for(i=1;i<=n;++i)printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
    return 0;
}
