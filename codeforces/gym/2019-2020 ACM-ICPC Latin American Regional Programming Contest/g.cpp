#include "bits/stdc++.h"
using namespace std;

#include <cstring>
#include <queue>
#define MAXS 500009
#define ALFA 26
#define MAXN 250009
char T[MAXN], P[MAXN];


class SuffixAutomaton {

	int len[MAXS], link[MAXS], cnt[MAXS];
	int nxt[MAXS][ALFA],sz,last,root;
	int newnode(){
		int x = ++sz;
		len[x] = 0; link[x] = -1; cnt[x]=1;
		for(int c=0; c<ALFA;c++)	nxt[x][c]=0;
		return x;
	}
	inline int reduce(char c){ return c -'A';}
public:
	SuffixAutomaton() {clear();}
	void clear() {
		sz=0;
		root=last=newnode();
	}
	void insert(const char *s){
		for(int i=0;s[i];i++) extend(reduce(s[i]));
	}
	void extend(int c){
		int cur = newnode(), p;
		len[cur] = len[last] + 1;
		for(p = last; p !=-1 && !nxt[p][c]; p = link[p]) {
			nxt[p][c] = cur;
		}
		if(p==-1) link[cur]=root;
		else{
			int q = nxt[p][c];
			if(len[p] + 1 == len[q]) link[cur]=q;
			else{
				int clone = newnode();
				len[clone] = len[p] + 1;
				for(int i=0;i<ALFA;i++){
					nxt[clone][i] = nxt[q][i];
				}
				link[clone] = link[q];
				cnt[clone]=0;
				while(p!=-1 && nxt[p][c]==q){
					nxt[p][c]=clone;
					p = link[p];
				}
				link[q]=link[cur]=clone;
			}
		}
		last=cur;
	}

	int contains(const char *s){
		int ans = 0;
		for(int i=0,p=root;s[i];i++){
			int c= reduce(s[i]);
			if(!nxt[p][c])	break;
			ans++;
			p=nxt[p][c];
		}
		return ans;
	}
};

SuffixAutomaton sa;

int main() {
	scanf("%s", T);
	sa.insert(T);
	int cnt;
	scanf("%d",&cnt);
	while(cnt--){

		scanf("%s",P);
		int ans = 0;

		int pos = 0;
		int len = strlen(P);

		while(pos<len){
			int tem = sa.contains(P+pos);
			if(tem == 0){
				ans=-1;	
				break;
			}
			ans++;
			pos+=tem;
		}
		printf("%d\n",ans);
	}

	return 0;

}