#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string s[50];
vector<string> word;
map<string,int> m;
int D[51][2][760],n;
int chk(string a,string b,int l){
    int i;
	for(i=0;i<l;++i)if(a[i]!=b[b.size()-i-1])return 0;
	return 1;
}
int f(int l,int d,string a){
	int i,j,k=m[a],len=a.size(),mn;
	int& ans=D[l][d][k];
	if(ans>=0)return ans;
	if(!l){
		for(i=0;i<len/2;++i)if(a[i]!=a[len-i-1])return ans=0;
		return ans=1;
	}
	ans=0;
	if(!d){
		for(i=0;i<n;++i){
            if(l<s[i].size())continue;
			mn=min(s[i].size(),a.size());
			if(chk(s[i],a,mn)){
				if(s[i].size()>len)ans+=f(l-s[i].size(),1,s[i].substr(mn));
				else ans+=f(l-s[i].size(),0,a.substr(0,len-mn));
			}
		}
	}
	else{
		for(i=0;i<n;++i){
            if(l<s[i].size())continue;
			mn=min(s[i].size(),a.size());
			if(chk(a,s[i],mn)){
				if(s[i].size()<len)ans+=f(l-s[i].size(),1,a.substr(mn));
				else ans+=f(l-s[i].size(),0,s[i].substr(0,s[i].size()-mn));
			}
		}
	}
	return ans;
}
int main(){
	int i,j,l;
	scanf("%d%d",&n,&l);
	for(i=0;i<n;++i){
        char t[20]={};
		scanf("%s",t);
		s[i]=t;
		for(j=0;t[j];++j){
		    word.push_back(s[i].substr(0,j+1));
			word.push_back(s[i].substr(j));
		}
	}
	sort(word.begin(),word.end());
	word.erase(unique(word.begin(),word.end()),word.end());
	for(i=0;i<word.size();)m[word[i]]=++i;
	memset(D,-1,sizeof D);
	D[0][0][0]=1;
	printf("%d",f(l,0,""));
	return 0;
}
