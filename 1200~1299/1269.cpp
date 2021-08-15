#include <stdio.h>
int main(){
    double a,b,c,p,q,h;
	scanf("%lf%lf%lf",&a,&b,&c);
	p=1,q=b;
	for(int i=1;i<1e2;++i){
		h=(p+q)/2;
		if(h<c)(h-a)/(1-a)+(h-b)/(1-b)+(h-c)/(1-c)<=1?q=h:p=h;
		else (h-a)/(1-a)+(h-b)/(1-b)-(h-c)/(1+c)<=1?q=h:p=h;
	}
	printf("%lf",q);
	return 0;
}
