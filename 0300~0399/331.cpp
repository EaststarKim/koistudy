#include <stdio.h>   
  
struct data   
  
{   
  
    int q[2];   
  
    int depth;   
  
    int depth_2;   
  
}a[100005];   
  
bool flag = 0;   
  
bool chk[100005];   
  
int answer=0;   
  
void dfs(int k)   
  
{   
  
    if(k==0) return;   
  
    int fr = a[k].q[0], bk = a[k].q[1];   
  
    dfs(fr); dfs(bk);   
  
    a[k].depth = a[fr].depth > a[bk].depth ? a[fr].depth+1:a[bk].depth+1;   
    a[k].depth_2 = a[fr].depth_2 <a[bk].depth_2? a[fr].depth_2+1: a[bk].depth_2+1;    
  
    return;   
  
}   
  
void solve(int k)   
  
{   
  
    if(flag==1) return;    
  
    if(k==0) return;   
  
    int fr = a[k].q[0], bk = a[k].q[1];   
  
    bool chk_1 = (a[fr].depth==a[fr].depth_2);    
    bool chk_2 = (a[bk].depth==a[bk].depth_2);    
    if(chk_1 == 1 && chk_2==1)    
  
    {   
  
        if(a[fr].depth<a[bk].depth) answer++;    
        else if(a[fr].depth == a[bk].depth) return;    
    }   
  
    else if(chk_1==0 && chk_2==0)    
  
    {   
  
        flag = 1; return;    
  
    }   
  
    else if(chk_1==1)   
  
    {   
  
        if(a[fr].depth < a[bk].depth) answer++;     
    }   
  
    else  
  
    {   
  
        if(a[fr].depth == a[bk].depth) answer++;    
  
    }   
  
    solve(fr); solve(bk);   
  
    return;   
  
}   
  
int main()   
  
{   
  
    int n,i;   
  
    scanf("%d",&n);   
  
    for(i=1;i<=n;i++)   
  
    {   
  
        scanf("%d %d",&a[i].q[0],&a[i].q[1]);   
  
        if(a[i].q[0] !=-1) chk[a[i].q[0]] = 1;   
  
        else a[i].q[0] = 0;   
  
        if(a[i].q[1] !=-1) chk[a[i].q[1]] = 1;   
  
        else a[i].q[1] = 0;   
  
    }   
  
    int root;   
  
    a[0].depth = 0;   
  
    a[0].depth_2 = 0;   
  
    for(i=1;i<=n;i++)   
  
    {   
  
        if(chk[i]==0)   
  
        {   
  
            root = i;   
  
            break;   
  
        }   
  
    }   
  
    dfs(root);   
  
    if(a[root].depth - a[root].depth_2 >1) flag = 1;   
  
    solve(root);   
  
    if(flag == 1) printf("-1");   
  
    else printf("%d",answer);   
  
    return 0;   
  
}  