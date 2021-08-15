#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef pair <int, char *> P;
char str[10005][100],text[10005],temp[30][100],S[30][100];
int b[30];
int main()
{
	int n,i,j,cnt=0;
	char te;
	priority_queue <P, vector <P>, greater<P> > q;
	scanf("%d %s",&n,text+1);
	for(i=1;i<=n;i++)
	{
		te=text[i];
		b[te-64]++;
		for(j=1;str[te-64][j]!='\0';j++);
		if(te!=str[te-64][j-1]||j==1)str[te-64][j]=te,str[te-64][j+1]='\0';
	}
	for(i=1;i<=26;i++)
	{
		if(b[i]!=0)
		{
			strcpy(temp[i],"");
			strcat(temp[i],str[i]+1);
			q.push(P(b[i],temp[i]));
			cnt++;
		}
	}
	if(cnt==1)
	{
		P s1=q.top();
		for(j=0;s1.second[j]!='\0';j++)strcat(S[s1.second[j]-64],"0");
		printf("%c %s\n",s1.second[0],S[s1.second[0]-64]);
	}
	else
	{
		while(q.size()>1)
		{
			P s1=q.top();q.pop();
			P s2=q.top();q.pop();
			for(j=0;s1.second[j]!='\0';j++)strcat(S[s1.second[j]-64],"0");
			for(j=0;s2.second[j]!='\0';j++)strcat(S[s2.second[j]-64],"1");
			q.push(P(s1.first+s2.first,strcat(s1.second,s2.second)));
		}
		for(i=1;i<=26;i++)
		{
			if(!strcmp(S[i],""))continue;
			printf("%c ",i+64);
			for(j=strlen(S[i])-1;j>=0;j--)printf("%c",S[i][j]);
			printf("\n");
		}
	}
	return 0;
}