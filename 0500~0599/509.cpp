#include<stdio.h>     // using set   
#include<set>   
using namespace std;   
int i,n,k;   
int d[15];   
bool check[15];   
set<int> numbers;   
void aa(int su,int lev)   
{   
    int i;   
    if(lev==k){   
        numbers.insert(su);   
        return;   
    }   
    for(i=0;i<n;i++){   
        if(check[i])continue;   
        check[i]=true;   
        if(d[i]<10)aa(su*10+d[i],lev+1);   
        else aa(su*100+d[i],lev+1);   
        check[i]=false;   
    }   
}   
int main()   
{   
    scanf("%d%d",&n,&k);   
    for(i=0;i<n;i++)scanf("%d",d+i);   
    aa(0,0);   
    printf("%d",numbers.size());   
    return 0;   
}  
