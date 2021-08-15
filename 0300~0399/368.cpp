#include <stdio.h>    
  
#include <vector>    
using namespace std;   
  
  
  
  
struct stone   
  
{   
  
    int ans[100];   
  
    int x,dif;   
  
};   
  
vector<stone> V[155];   
  
int abs(int k)   
  
{   
  
    return k>0? k:-k;   
  
}   
  
int main()   
  
{   
  
    int n,m,i,j,k,l,tmp;   
  
    stone tmp_s;   
  
    for(i=0;i<100;i++) tmp_s.ans[i] = -1;   
  
    scanf("%d %d",&n,&m);   
  
    for(i=0;i<n;i++)   
  
    {   
  
        scanf("%d",&tmp);   
  
        for(j=0;j<tmp;j++)   
  
        {   
  
            int a,b;   
  
            scanf("%d %d",&a,&b);   
  
            tmp_s.x = a; tmp_s.dif = b;   
  
            V[i].push_back(tmp_s);   
  
        }   
  
    }   
  
    for(i=0;i<n;i++)   
  
    {   
  
        for(j=0;j<V[i].size();j++)   
  
        {   
  
            if(i==0) V[i][j].ans[0] = 0;   
  
            else  
  
            {   
  
                for(k=0;k<=(i+1)/2&&k<=m;k++)   
  
                {   
  
                    if(i==1 && k==1)   
  
                    {   
  
                        V[i][j].ans[1] = 0;   
  
                        break;   
  
                    }   
  
                    V[i][j].ans[k] = -1;   
  
                    for(l=0;l<V[i-1].size();l++)   
  
                    {   
  
                        if(V[i-1][l].ans[k]==-1) continue;   
  
                        int tmp = V[i-1][l].ans[k] + (long long int)(V[i][j].dif + V[i-1][l].dif) * abs(V[i][j].x - V[i-1][l].x);   
  
                        if(V[i][j].ans[k] > tmp || V[i][j].ans[k]==-1)   
  
                        V[i][j].ans[k] = tmp;   
  
                    }   
  
                    if(i!=0&&k!=0)   
  
                    {   
  
                        for(l=0;l<V[i-2].size();l++)   
  
                        {   
  
                            if(V[i-2][l].ans[k-1]==-1) continue;   
  
                            int tmp = V[i-2][l].ans[k-1] + (V[i][j].dif + V[i-2][l].dif) * abs(V[i][j].x - V[i-2][l].x);   
  
                            if(V[i][j].ans[k] > tmp||V[i][j].ans[k] ==-1 )   
  
                            V[i][j].ans[k] = tmp;   
  
                        }   
  
                    }   
  
                }   
  
            }   
  
        }   
  
    }   
  
    int min = -1;   
  
    for(i=0;i<V[n-1].size();i++)   
  
    {   
  
        for(j=0;j<=m;j++)   
  
        {   
  
            if((V[n-1][i].ans[j] < min && V[n-1][i].ans[j] >=0)||min==-1) min = V[n-1][i].ans[j];   
  
        }   
  
    }   
  
    for(i=0;i<V[n-2].size();i++)   
  
    {   
  
        for(j=0;j<m;j++)   
  
        {   
  
            if((V[n-2][i].ans[j] < min && V[n-2][i].ans[j] >=0)||min==-1) min = V[n-2][i].ans[j];   
  
        }   
  
    }   
  
    printf("%d",min);   
  
    return 0;   
  
}  