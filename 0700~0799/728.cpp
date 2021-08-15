#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map<int,map<int,int> > m;
int x[]={1,0,-1,0},y[]={0,1,0,-1},sr=1e9,sc=1e9,d,ans;
int main(){
    int i,n,r,c;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&r,&c);
        m[c][r]=1;
        if(c<sc||(c==sc&&r<sr))sr=r,sc=c;
    }
    r=sr,c=sc;
    for(;;){
        ++ans;
        c+=x[d],r+=y[d];
        for(d=(d+3)%4;;d=(d+1)%4)if((!d&&m[c][r])||(d==1&&m[c-1][r])||(d==2&&m[c-1][r-1])||(d>2&&m[c][r-1]))break;
        if(r==sr&&c==sc)break;
    }
    printf("%d",ans);
    return 0;
}
