#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	x=abs(x-y);
	printf("%d",x/10+min(11-x%10,min(x%10,abs(x%10-5)+1)));
	return 0;
}
