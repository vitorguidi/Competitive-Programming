#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

int id[100100];
int sz[100100];
int his[100100];
int clk=1;

int find(int a, int t){

	if(id[a]==a)	return a;
	if(his[a]>t)	return a;
	return find(id[a],t);

}

void join(int a, int b){
	a=find(a,clk);b=find(b,clk);
	if(a==b){
		clk++;
		return;
	}
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	his[b]=clk++;
	sz[a]+=sz[b];

}

bool check(int t, int a, int b){
	return find(a,t)==find(b,t);
}

void go(){

	int n,m;
	scanf("%d %d",&n,&m);

	clk=1;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
		his[i]=0;
	}

	frr(i,m){
		
		int op,u,v;
		scanf("%d %d %d",&op,&u,&v);
		
		if(op==1){
			join(u,v);
			continue;
		}
		
		int ini=0;
		int end=clk;
		int best=-1;

		while(ini<=end){
			int mid = (ini+end)>>1;
			if(check(mid,u,v)){
				best=mid;
				end=mid-1;
			}
			else	ini=mid+1;
		}
		clk++;
		printf("%d\n",best);

	}


}
int main(){

	fastio;

	int t;scanf("%d",&t);
	while(t--)	go();
	
}