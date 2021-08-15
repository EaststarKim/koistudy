#include <stdio.h>
#include <string.h>
using namespace std;
char c[20];
int n;
long long ans;
void f(int p,long long s,long long t){
    if(p>n){
        ans+=s;
        return;
    }
    if(t)f(p+1,s+t,c[p+1]-'0');
    if(p<n)f(p+1,s,t*10+c[p+1]-'0');
}
int main(){
    int i;
    scanf("%s",c+1);
    n=strlen(c+1);
    f(1,0,c[1]-'0');
    printf("%lld",ans);
    return 0;
}
