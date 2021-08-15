#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
struct data{
    char a[11];
    int d;
}q[400000];
int d[]={-3,3,-1,1},f,r=1;
char c[11];
string w;
map<string,int> chk;
int main(){
    int i,j,n;
    for(i=1;i<10;++i)scanf(" %c",&q[1].a[i]);
    for(i=1;i<10;++i)if(q[1].a[i]=='0')q[1].a[i]=57;
    w=q[1].a+1;
    chk[q[1].a+1]=1;
    while(f<r){
        ++f;
        if(q[f].d>20)break;
        w=q[f].a+1;
        for(i=1;i<10;++i)if(q[f].a[i]!=i+48)break;
        if(i>9){
            printf("%d",q[f].d);
            return 0;
        }
        if(q[f].d>19)continue;
        for(i=1;i<10;++i)if(q[f].a[i]>56)break;
        for(j=0;j<4;++j){
            if(j==2&&i%3==1)continue;
            if(j==3&&i%3==0)continue;
            n=i+d[j];
            if(n<1||n>9)continue;
            strcpy(c+1,q[f].a+1);
            swap(c[i],c[n]);
            w=c+1;
            if(chk[w])continue;
            chk[w]=1;
            strcpy(q[++r].a+1,c+1);
            q[r].d=q[f].d+1;
        }
    }
    puts("-1");
    return 0;
}
