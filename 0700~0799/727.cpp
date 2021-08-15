#include <stdio.h>
#include "lib.h"
#include <algorithm>
using namespace std;
double a[1000010];
int main(){
	int i,n;
	n=Sizef();
	for(i=0;i<n;++i)a[i]=Getf(i);
	sort(a,a+n);
	for(i=0;i<n;++i)Putf(a[i],i);
	done();
	return 0;
}
