#include <stdio.h>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> cd;
typedef vector<cd> vcd;
char a[30010],b[30010];
void fft(vcd &a,bool invert){
    int i,j,bit,len,n=a.size();
    for(i=1,j=0;i<n;++i){
        bit=n>>1;
        for(;j>=bit;bit>>=1)j-=bit;
        j+=bit;
        if(i<j)swap(a[i],a[j]);
    }
    for(len=2;len<=n;len<<=1){
        double ang=2*M_PI/len*(invert?-1:1);
        cd wlen(cos(ang),sin(ang));
        for(i=0;i<n;i+=len){
            cd w(1);
            for(j=0;j<len/2;++j){
                cd u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert)for(i=0;i<n;++i)a[i]/=n;
}
void multiply(vector<int> &a,vector<int> &b,vector<int> &ret){
    int i,M2;
    for(M2=1;M2<=max(a.size(),b.size());M2<<=1);
    M2<<=1;
    vcd va(M2),vb(M2);
    for(i=0;i<a.size();++i)va[i]=a[i];
    for(i=0;i<b.size();++i)vb[i]=b[i];
    fft(va,false),fft(vb,false);
    for(i=0;i<M2;++i)va[i]*=vb[i];
    fft(va,true);
    ret.resize(M2);
    for(i=0;i<M2;++i)ret[i]=round(va[i].real());
}
int main(){
    int i;
    vector<int> x,y,z;
    scanf("%s\n%s",a,b);
    for(i=0;a[i];++i)x.push_back(a[i]-48);
    for(i=0;b[i];++i)y.push_back(b[i]-48);
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    multiply(x,y,z);
    z.push_back(0);
    for(i=0;i<z.size()-1;++i)z[i+1]+=z[i]/10,z[i]%=10;
    while(!z[i])--i;
    for(;i>=0;--i)printf("%d",z[i]);
    return 0;
}
