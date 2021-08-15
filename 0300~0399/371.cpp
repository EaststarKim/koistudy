#include <stdio.h>   
  
#include <algorithm>   
  
using namespace std;   
  
class lad   
  
{   
  
    public:   
  
    int loc,ind_1,ind_2,h;   
  
    bool operator < (const lad& p) const  
  
    {   
  
        return h < p.h;   
  
    }   
  
}a[100005];   
  
int ans[1005];   
  
int l[1005];   
  
int score[1005];   
  
int main()   
  
{   
  
    int n,m,tmp,x,i;   
  
    scanf("%d %d %d %d",&n,&m,&tmp,&x);   
  
    for(i=1;i<=n;i++)   
  
    {   
  
        scanf("%d",score+i);   
  
        ans[i] = i;    
  
    }   
  
    for(i=0;i<m;i++)   
  
        scanf("%d %d",&a[i].loc,&a[i].h);   
  
    sort(a,a+m);    
  
    for(i=0;i<m;i++)   
  
    {   
  
        a[i].ind_1 = ans[a[i].loc];   
  
        a[i].ind_2 = ans[a[i].loc+1];    
  
        tmp = ans[a[i].loc];   
  
        ans[a[i].loc] = ans[a[i].loc+1];   
  
        ans[a[i].loc+1] = tmp;   
  
    }   
  
    int cnt = 0;   
  
    for(i=1;i<=n;i++)   
  
        l[ans[i]] = i;    
  
    for(i=1;i<=x;i++)   
  
        cnt+=score[l[i]];    
  
    int answer = cnt;   
  
    for(i=0;i<m;i++)   
  
    {   
  
        if(a[i].ind_1 <=x && a[i].ind_2 > x)   
  
        {   
  
            if(answer > cnt - score[l[a[i].ind_1]] + score[l[a[i].ind_2]])   
  
                answer = cnt - score[l[a[i].ind_1]] + score[l[a[i].ind_2]];   
  
        }   
  
        else if(a[i].ind_2 <=x && a[i].ind_1 > x)   
  
        {   
  
            if(answer > cnt - score[l[a[i].ind_2]] + score[l[a[i].ind_1]])   
  
                answer = cnt - score[l[a[i].ind_2]] + score[l[a[i].ind_1]];   
  
        }   
  
    }   
  
    printf("%d",answer);   
  
    return 0;   
  
}  