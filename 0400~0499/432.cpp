#include <stdio.h>   
  
#include <algorithm>   
  
int a[50005];   
  
bool chk[50005];   
  
int main()   
  
{   
  
    int d,n,m,i;   
  
    scanf("%d %d %d",&d,&n,&m);   
  
    for(i=1;i<=n;i++) scanf("%d",a+i);   
  
    a[0] = 0;   
  
    std::sort(a,a+n+1);   
  
    int fr=1,bk=d,mid;   
  
    while(fr<bk)   
  
    {   
  
        mid = (fr+bk+1)/2;   
  
        int tmp = 0;   
  
        int cnt=0;   
  
        for(i=1;i<=n;i++)   
  
        {   
  
            if(a[i] - a[tmp] < mid)   
  
            {   
  
                cnt++;   
  
                chk[i] = 1;   
  
            }   
  
            else tmp = i;   
  
        }   
  
        for(;tmp>=0;tmp--)   
  
        {   
  
            if(d - a[tmp] < mid)    
  
            {   
  
                if(chk[tmp] == 0)   
  
                    cnt++;   
  
            }   
  
            else break;   
  
        }   
  
        if(cnt <= m) fr = mid;   
  
        else bk = mid-1;   
        for(i=0;i<=n;i++) chk[i] = 0;   
  
    }   
  
    printf("%d",fr);   
  
    return 0;   
  
} 