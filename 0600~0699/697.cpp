#include<stdio.h>   
int n,w[20001],i,IT[70000],l,R[20001],B,E,M,S;   
int find(int p){   
    B=l,E=l+p,S=0;   
    while(B<=E){   
        if(B&1)S+=IT[B];   
        if(!(E&1))S+=IT[E];   
        B=(B+1)/2,E=(E-1)/2;   
    }   
    return S;   
}   
int main()   
{   
    int b,e,m,t;   
    scanf("%d",&n);   
    l=1;   
    while(l<n)l*=2;   
    for(i=0;i<n;i++){   
        scanf("%d",&w[i]);   
        t=i+l;while(t)IT[t]++,t/=2;}   
    for(i=n-1;i>=0;i--){   
        b=0,e=n-1;   
        while(b<=e){   
            m=(b+e+1)/2;   
            if(IT[m+l]==0){   
                if(find(m)>=w[i])e=m-1;   
                else b=m+1;}   
            else{   
                t=find(m);   
                if(t==w[i])break;   
                if(t<w[i])b=m+1;   
                else e=m-1;   
            }   
        }   
        R[m]=i;   
        t=m+l;while(t)IT[t]--,t/=2;   
    }   
    for(i=0;i<n;i++)printf("%d\n",R[i]+1);   
}  
