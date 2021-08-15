#include<stdio.h>   
#include<memory.h>   
int pre,n,qqq[510][2],x[510],chk[510],dap=1<<30,lll[510],z;   
struct data{   
    int a,b;
} indextree[1<<12];   
  
int i,j,maxx;   
  
int f(int a,int b){   
    int M=0;   
    while(a<b){   
        if(~b&1){   
            if(M<indextree[b].b)   
                M=indextree[b].b;   
            b--;   
        }   
        a>>=1,b>>=1;   
    }   
    if(a==b&&M<indextree[a].b)M=indextree[a].b;   
    return M;   
}   
int main(){   
    scanf("%d",&n);   
    for(i=1;i<=n;i++)scanf("%d%d",qqq[i],qqq[i]+1);   
    pre=x[0]=chk[1]=1;   
    for(i=1;i<n;i++){   
        if(chk[qqq[pre][0]]==0){   
            chk[qqq[pre][0]]=1;   
            x[i]=qqq[pre][0];   
            pre=qqq[pre][0];   
        }   
        else if(chk[qqq[pre][1]]==0){   
            chk[qqq[pre][1]]=1;   
            x[i]=qqq[pre][1];   
            pre=qqq[pre][1];   
        }   
        else break;   
    }   
    if(i!=n || (qqq[x[n-1]][0]!=1 && qqq[x[n-1]][1]!=1))return printf("-1");   
  
    for(z=0;z<n;z++){   
        memset(indextree,0,sizeof(indextree));   
        for(i=0;i<n;i++)   
            lll[i]=x[(i+z)%n];   
        int p;   
        for(p=1;p<=n;p*=2);   
        for(i=0;i<n;i++){   
            int t=p+lll[i]-1;   
            indextree[t].a=1;   
            indextree[t].b=f(p,t-1)+1;   
            for(j=t;j>1;j>>=1){   
                if(indextree[j>>1].a==0)indextree[j>>1]=indextree[j];   
                else if(indextree[j>>1].b<indextree[j].b)indextree[j>>1]=indextree[j];   
            }   
        }   
        if(n-indextree[1].b<dap)dap=n-indextree[1].b;   
    }   
    for(i=0;i<n/2;i++){   
        int t=x[i];   
        x[i]=x[n-i-1];   
        x[n-i-1]=t;   
    }   
    for(z=0;z<n;z++){   
        memset(indextree,0,sizeof(indextree));   
        for(i=0;i<n;i++)   
            lll[i]=x[(i+z)%n];   
        int p;   
        for(p=1;p<=n;p*=2);   
        for(i=0;i<n;i++){   
            int t=p+lll[i]-1;   
            indextree[t].a=1;   
            indextree[t].b=f(p,t-1)+1;   
            for(j=t;j>1;j>>=1){   
                if(indextree[j>>1].a==0)indextree[j>>1]=indextree[j];   
                else if(indextree[j>>1].b<indextree[j].b)indextree[j>>1]=indextree[j];   
            }   
        }   
        if(n-indextree[1].b<dap)dap=n-indextree[1].b;   
    }   
    printf("%d",dap);   
}  
