#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
char c[10010];
int main(){
    int n,l,r,k;
    string str;
    scanf("%s",c);
    str=c;
    scanf("%d",&n);
    for(;n--;){
        scanf("%d%d%d",&l,&r,&k);
        --l,--r;
        k%=(r-l+1);
        string a=str.substr(0,l);
        string b=str.substr(r-k+1,k);
        string c=str.substr(l,r-k-l+1);
        string d=str.substr(r+1);
        str=a+b+c+d;
    }
    printf("%s",str.c_str());
    return 0;
}
