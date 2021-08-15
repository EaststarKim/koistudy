#include <stdio.h>
#include <map>
#include <string>
using namespace std;
map<string,int> t;
char a[5010],b[5010];
int main(){
    int i,j,n,cnt=0;
    scanf("%d\n%s",&n,&a);
    for(i=1;i<=n;++i){
        for(j=0;j<n;++j)b[n-j-1]=a[j];
        string x=a,y=b;
        if(!t[x]&&!t[y])t[x]=t[y]=1,++cnt;
        for(j=n;j;--j)a[j]=a[j-1];
        a[0]=a[n],a[n]=0;
    }
    printf("%d",cnt);
    return 0;
}
