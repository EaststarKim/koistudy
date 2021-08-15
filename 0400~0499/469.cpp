#include <stdio.h>

#include <algorithm>

#include <set>

using namespace std;

set<int> S;

int Q[50005];

int color[50005],ind;

class data

{

    public:

    int x,c;

    bool operator < (const data &p) const

    {

        return x < p.x;

    }

}a[50005];

int main()

{

    int n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {

        scanf("%d %d",&a[i].x,&a[i].c); 

        if(S.count(a[i].c)==0)

        {

            color[ind++] = a[i].c;

            S.insert(a[i].c);

        }

    }

    sort(color,color+ind);

    for(i=0;i<n;i++)

    {

        int fr=0,bk = ind-1,mid;

        while(fr!=bk)

        {

            mid = (fr+bk)/2;

            if(color[mid]==a[i].c) break;

            else if(color[mid] < a[i].c) fr = mid+1;

            else bk = mid-1;

        }

        mid = (fr+bk)/2;

        a[i].c = mid;

    }

    sort(a,a+n);

    int fr = 0,cnt=0,answer = 0x7fffffff; 
    for(i=0;i<n;i++)

    {

        if(Q[a[i].c]==0) cnt++;

        Q[a[i].c]++; 
        for(;fr<i;fr++)

        {

            if(Q[a[fr].c]>1) Q[a[fr].c]--; 

            else break;

        }

        if(cnt==ind && answer > a[i].x-a[fr].x) answer = a[i].x-a[fr].x;

    }

    printf("%d",answer);

    return 0;

}

