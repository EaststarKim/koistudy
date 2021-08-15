#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
char c[2010];
int main(){
    int i,j,k,t;
    string ans;
    scanf("%s\n%d",c,&k);
    for(i=0;c[i];++i)ans+=c[i];
    for(i=0;c[i];++i){
        string w;
        t=k;
        for(j=i;c[j];++j){
            if(c[j]!='a'&&t)--t,w+='a';
            else w+=c[j];
        }
        for(j=0;j<i;++j){
            if(c[j]!='a'&&t)--t,w+='a';
            else w+=c[j];
        }
        ans=min(ans,w);
    }
    printf("%s",ans.c_str());
    return 0;
}
