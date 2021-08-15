#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h;
    scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
    a=max(max(c,g)-min(a,e),max(d,h)-min(b,f));
    printf("%d",a*a);
    return 0;
}
