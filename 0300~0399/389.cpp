#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

class data

{

    public:

    int dis,p,q;

    bool operator < (const data& t) const 
    {

        return dis < t.dis;

    }

};

vector<data> V;

int uni[100005];

int root(int k)

{

    if(uni[k] == k) return k;

    else

    {

        uni[k] = root(uni[k]);

        return uni[k];

    }

}

int main()

{

    int n,m,k,i,j;

    scanf("%d %d %d",&n,&m,&k);

    for(i=0;i<m;i++)

    {

        int a,b,c;

        data tmp;

        scanf("%d %d %d",&a,&b,&c);

        tmp.dis = c;

        tmp.p = b;

        tmp.q = a;

        V.push_back(tmp);

    }

    for(i=1;i<=n;i++) uni[i]= i;

    sort(V.begin(),V.end());

    int cnt = 0,answer =0;

    for(i=0;i<m&& cnt<n-k;i++)

    {

        int a = root(V[i].p), b = root(V[i].q);

        if(a==b) continue;

        cnt++;

        uni[a] = b;

        answer += V[i].dis; 

    }

    printf("%d",answer);

    return 0;

}