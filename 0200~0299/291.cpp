#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX=100010;
long long a[MAX],k,heap[MAX*100]={1},r=1,b[110];
bool comp(const long long &l, const long long &r){
	return l>r;
}
int main()
{
	int i,x,y,n;
	scanf("%d%d",&x,&y);
	for(i=0;i<x;++i)scanf("%d",&b[i]);
	while(n<=y){
		a[n++]=k=heap[0];
		while(r&&k==heap[0]){
			pop_heap(heap,heap+r,comp);
			r--;
		}
		for(i=0;i<x;++i){
			heap[r++]=k*b[i];
			push_heap(heap,heap+r,comp);
		}
	}
	printf("%lld",a[y]);
	return 0;
}

