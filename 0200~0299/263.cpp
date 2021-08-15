#include <stdio.h>
#define F(i) for(i=0;i<4;++i)
#define FF(a) for(j=0;j<a;++j)
int A[9],s=1e6,ans[300000];
int M(int n){return n%4?n%4:4;}
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    for(j=0;j<9;++j)scanf("%d",A+j),A[j]/=3;
    F(a)F(b)F(c)F(d)F(e)F(f)F(g)F(h)F(i){
        if(M(A[0]+a+b+d)+M(A[1]+a+b+c+e)+M(A[2]+b+c+f)+M(A[3]+a+d+e+g)+M(A[4]+a+c+e+g+i)+M(A[5]+c+e+f+i)+M(A[6]+d+g+h)+M(A[7]+e+g+h+i)+M(A[8]+f+h+i)<36)continue;
        if(a+b+c+d+e+f+g+h+i<s){
            FF(a)ans[j]=1;
            s=a;
            FF(b)ans[j+s]=2;
            s+=b;
            FF(c)ans[j+s]=3;
            s+=c;
            FF(d)ans[j+s]=4;
            s+=d;
            FF(e)ans[j+s]=5;
            s+=e;
            FF(f)ans[j+s]=6;
            s+=f;
            FF(g)ans[j+s]=7;
            s+=g;
            FF(h)ans[j+s]=8;
            s+=h;
            FF(i)ans[j+s]=9;
            s+=i;
        }
    }
    FF(s)printf("%d ",ans[j]);
    return 0;
}
