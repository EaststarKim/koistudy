#include <stdio.h>      
#include <math.h>      
#include <algorithm>      
#define MIN(x,y) ((x)<(y)?(x):(y))      
     
int n;      
double ANS;           
     
struct X{      
    double x,y;      
}a[10005];      
     
bool cmp_x(X aa, X bb){      
    if(aa.x!=bb.x) return aa.x<bb.x;      
    return aa.y<bb.y;      
}      
bool cmp_y(X aa, X bb){      
    if(aa.y!=bb.y) return aa.y<bb.y;      
    return aa.x<bb.x;      
}      
     
double len(X aa, X bb){return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));}      
     
     
double f(int left, int right){      
    if(left==right) return ANS;      
    if(left+1==right) return len(a[left],a[right]);      
     
    double min1, min2, min, Min;      
    int mid;      
    mid=(left+right)>>1;      
     
    min1=f(left,mid);      
    printf("",min1);      
    min2=f(mid+1,right);      
    ANS=min=Min=MIN(min1,min2);      
     
    int i,j,k,l;      
     
    for(i=mid;i>left;i--) if(a[mid].x-min>a[i].x) break; left=i+1;      
    for(i=mid;i<=right;i++) if(a[i].x>a[mid].x+min) break; right=i-1;      
     
     
    std::sort(a+left,a+right+1,cmp_y);      
     
    for(i=j=left;j<=right;j++){      
        while(a[j+1].y<a[i].y+min && j+1<=right) j++;      
        for(k=i;k<=j;k++){      
            for(l=k+1;l<=j;l++){      
                Min=MIN(Min,len(a[k],a[l]));      
            }      
        }      
     
    }      
     
    std::sort(a+left,a+right+1,cmp_x);      
     
    return Min;      
}      
int main(){      
    int i;      
    scanf("%d",&n);      
    for(i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);      
    std::sort(a+1,a+1+n,cmp_x);      
    ANS=len(a[1],a[2]);      
    printf("%.2lf",f(1,n));
	return 0;
}  