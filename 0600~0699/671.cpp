#include <stdio.h>   
#include <vector>   
#include <algorithm>   
#include <math.h>
using namespace std;   
struct data 
{   
    int x,y;   
    int ind;   
}a[100005]; 
vector<int> V[100005];   
int ans[100005],chk[100005];   
long double dis[100005];   
bool cmp_sort(data p, data q)   
{   
    return p.x+p.y < q.x+q.y;    
}   
bool isconnect(data p, data q)   
{   
    return p.x < q.x && p.y < q.y;    
} 
long double dist(data p, data q)     
{   
    return (long double)sqrt((long double)(p.x-q.x)*(long double)(p.x-q.x) + (long double)(p.y-q.y)*(long double)(p.y-q.y));    
}   
int main()   
{   
    int n,m,i,j;   
    scanf("%d %d",&n,&m);   
    for(i=1;i<=n;i++) 
    {   
        scanf("%d %d",&a[i].x,&a[i].y);   
        a[i].ind = i;   
    }
    sort(a+1,a+n+1,cmp_sort);   
    for(i=1;i<=n;i++) chk[a[i].ind] = i;   
    for(i=0;i<m;i++)   
    {   
        int tmp_1,tmp_2;   
        scanf("%d %d",&tmp_1,&tmp_2);   
        tmp_1 = chk[tmp_1];   
        tmp_2 = chk[tmp_2];   
        if(isconnect(a[tmp_1],a[tmp_2])) V[tmp_2].push_back(tmp_1);   
        else if(isconnect(a[tmp_2],a[tmp_1])) V[tmp_1].push_back(tmp_2);   
    } 
    int answer_max=0;   
    long double answer_dis=0.0;   
    for(i=1;i<=n;i++)   
    {   
        int maximum=1;   
        long double distance = 0.0;   
        for(j=0;j<V[i].size();j++)   
        {   
            if(maximum < ans[V[i][j]]+1 || (maximum == ans[V[i][j]]+1 && distance < dis[V[i][j]] + dist(a[i],a[V[i][j]])))   
            {   
                maximum = ans[V[i][j]] + 1;   
                distance = dis[V[i][j]] + dist(a[i],a[V[i][j]]);   
            }   
        }  
        ans[i] = maximum;   
        dis[i] = distance;  
        if(answer_max < maximum ||(answer_max == maximum && answer_dis < distance))\   
        { 
            answer_max = maximum;   
            answer_dis = distance;   
        }   
    }   
    printf("%d\n%Lf",answer_max,answer_dis);   
    return 0;   
}  