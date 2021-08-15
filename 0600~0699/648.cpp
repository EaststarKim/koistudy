#include <stdio.h>
#include <map>
using namespace std;
map<int,int> D;
int a[51],m;
int f(int n){
    int i,s=0;
    if(!n)return 1;
    if(D[n])return D[n];
    for(i=1;i<=m;++i)if(n>=a[i])s+=f(n-a[i]);
    return D[n]=s%1000000;
}
int main(){
    int i,n,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d",a+i);
    printf("%d",(t=f(n))?t:-1);
    return 0;
}
