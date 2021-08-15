#include <stdio.h>
int main(){
    int a,b,c,d,e,f,n,mx=0,mi;
    long long t=1;
    scanf("%d",&n);
    for(a=0;a<24;++a){
        if(t>n)break;
        for(b=0;b<15;++b){
            if(t>n)break;
            for(c=0;c<11;++c){
                if(t>n)break;
                for(d=0;d<9;++d){
                    if(t>n)break;
                    for(e=0;e<7;++e){
                        if(t>n)break;
                        for(f=0;f<7;++f){
                            if(t>n)break;
                            if(mx<=(a+1)*(b+1)*(c+1)*(d+1)*(e+1)*(f+1)){
                                if(mx==(a+1)*(b+1)*(c+1)*(d+1)*(e+1)*(f+1)){
                                    if(mi>t)mi=t;
                                }
                                else mx=(a+1)*(b+1)*(c+1)*(d+1)*(e+1)*(f+1),mi=t;
                            }
                            t*=13;
                        }
                        for(;f--;)t/=13;
                        t*=11;
                    }
                    for(;e--;)t/=11;
                    t*=7;
                }
                for(;d--;)t/=7;
                t*=5;
            }
            for(;c--;)t/=5;
            t*=3;
        }
        for(;b--;)t/=3;
        t*=2;
    }
    printf("%d",n-mi+1);
    return 0;
}
