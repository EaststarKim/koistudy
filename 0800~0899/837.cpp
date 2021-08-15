#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int i,j,k,d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
}t;
priority_queue<data> q;
int a[1010],D[1010][1010][2];
int main(){
    int i,j,k,d,n,s;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(i=1;i<=n&&a[i]<s;++i);
    if(a[i]==s)q.push({i,i,0,D[i][i][0]=1});
    else{
        if(i>1)q.push({i-1,i-1,0,D[i-1][i-1][0]=n*(s-a[i-1])+1});
        if(i<=n)q.push({i,i,0,D[i][i][0]=n*(a[i]-s)+1});
    }
    while(!q.empty()){
        t=q.top();
        i=t.i,j=t.j,k=t.k,d=t.d;
        q.pop();
        if(d!=D[i][j][k])continue;
        if(i==1&&j==n){
            printf("%d",D[i][j][k]-1);
            return 0;
        }
        if(i>1&&(!D[i-1][j][0]||D[i-1][j][0]>d+(n-j+i-1)*((k?a[j]:a[i])-a[i-1])))q.push({i-1,j,0,D[i-1][j][0]=d+(n-j+i-1)*((k?a[j]:a[i])-a[i-1])});
        if(j<n&&(!D[i][j+1][1]||D[i][j+1][1]>d+(n-j+i-1)*(a[j+1]-(k?a[j]:a[i]))))q.push({i,j+1,1,D[i][j+1][1]=d+(n-j+i-1)*(a[j+1]-(k?a[j]:a[i]))});
    }
}
