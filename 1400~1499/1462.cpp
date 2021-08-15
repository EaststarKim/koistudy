#include <stdio.h>
#include <algorithm>
using namespace std;
int c[100010],b[100010],h[100010],p[100010],n;
int findSample(){
    int i;
    for(i=n;--i;){
        if(!p[i]){
            c[h[i]]+=b[i];
            b[h[i]]+=max(c[i],b[i]);
        }
        else if(p[i]==1){
            c[h[i]]=max(c[h[i]]+max(c[i],b[i]),b[h[i]]+c[i]);
            b[h[i]]+=b[i];
        }
        else{
            c[h[i]]=max(c[h[i]]+b[i],b[h[i]]+c[i]);
            b[h[i]]+=b[i];
        }
    }
    return max(c[0],b[0]);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",c+i);
    for(i=1;i<n;++i)scanf("%d%d",h+i,p+i);
    printf("%d",findSample());
    return 0;
}
