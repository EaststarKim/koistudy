#include <stdio.h>         
long long int M;         
long long int C[55], p[55];         
int ncr(int n, int r){         
    long long int j,t=n,s=1;         
    for(j=1;j<=r;j++){         
        s=s*t/j;         
        t--;         
        C[j]=s;         
    }         
    return 0;         
}         
int pizza(int n, int k){         
    if(k==0) return 0;         
    long long int j,res1=1,res2=1;         
    for(j=1;j<=n;j++) res1=(res1*(k-1))%M;         
    if(n%2==0) res2=(k-1)%M;         
    else res2=(1-k)%M;         
    if((res1+res2)%M<0) return ((res1+res2)%M)+M;         
    else return (res1+res2)%M;         
}         
        
int main(){         
    long long int n,k,i,res;         
    scanf("%lld%lld%lld",&n,&k,&M);         
    if(n==1){         
        if(k==1){         
            printf("%lld",1%M);         
            return 0;         
        }         
        else{         
            printf("0");         
            return 0;         
        }         
    }         
    if(n<k){         
        printf("0");         
        return 0;         
    }         
    for(i=k;i>=0;i--){         
        p[i]=pizza(n,i);         
    }         
    for(i=1;i<=k;i++) C[i]%=M;         
    res = p[k];         
    ncr(k,k);         
    C[0]=1;         
    for(i=k-1;i>=0;i=i-2){         
        res+=((-C[i])*p[i]+C[i-1]*p[i-1])%M;         
    }         
    if(res%M<0) printf("%lld\n",(res%M)+M);         
    else printf("%lld\n",res%M);         
    return 0;         
}  