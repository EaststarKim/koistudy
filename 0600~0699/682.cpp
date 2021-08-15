#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct data{
    double x,y;
    bool operator<(const data&r)const{
        return y<r.y;
    }
}a[4];
int main(){
    int i;
    double s=0,x1,x2;
    for(i=0;i<3;++i)scanf("%lf%lf",&a[i].x,&a[i].y);
    a[3]=a[0];
    for(i=0;i<3;++i)s+=a[i].x*a[i+1].y-a[i+1].x*a[i].y;
    s=fabs(s)/2;
    sort(a,a+3);
    if(a[2].y<0)s=0;
    else if(a[1].y<0){
        x1=a[0].x-a[0].y*(a[2].x-a[0].x)/(a[2].y-a[0].y);
        x2=a[1].x-a[1].y*(a[2].x-a[1].x)/(a[2].y-a[1].y);
        s=a[2].y*fabs(x2-x1)/2;
    }
    else if(a[0].y<0){
        x1=a[2].x-a[2].y*(a[0].x-a[2].x)/(a[0].y-a[2].y);
        x2=a[1].x-a[1].y*(a[0].x-a[1].x)/(a[0].y-a[1].y);
        s+=a[0].y*fabs(x2-x1)/2;
    }
    printf("%.f",s);
    return 0;
}
