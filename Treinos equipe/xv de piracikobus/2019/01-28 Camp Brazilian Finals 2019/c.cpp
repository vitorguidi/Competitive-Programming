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
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

typedef tuple<int,int,int> tup;

int n,m,k;
int id1[31234],id2[31234],sz1[31234],sz2[31234];
vector<tup> ans;
vector<pii> tp1,tp2;

int find1(int a){
	if(id1[a]==a)
		return a;
	return id1[a]=find1(id1[a]);	
}
void merge1(int a,int b){
	a=find1(a);
	b=find1(b);
	if(a==b) return;

	if(sz1[a]<sz1[b])
		swap(a,b);
	id1[b]=a;
	sz1[a]+=sz1[b];
}


int find2(int a){
	if(id2[a]==a)
		return a;
	return id2[a]=find2(id2[a]);	
}
void merge2(int a,int b){
	a=find2(a);
	b=find2(b);
	if(a==b) return;

	if(sz2[a]<sz2[b])
		swap(a,b);
	id2[b]=a;
	sz2[a]+=sz2[b];
}

void kruskal(){
	for(auto x:tp2){
		if(find2(x.fst)!=find2(x.snd))
			merge2(x.fst,x.snd);
	}

	for(auto x:tp1){
		if(find2(x.fst)!=find2(x.snd) && k){
			merge2(x.fst,x.snd);
			merge1(x.fst,x.snd);
			ans.pb({x.fst,x.snd,0});
			k--;
		}
	}

	for(auto x:tp1){
		if(find1(x.fst)!=find1(x.snd) && k){
			merge1(x.fst,x.snd);
			ans.pb({x.fst,x.snd,0});
			k--;
		}
	}
	for(auto x:tp2){
		if(find1(x.fst)!=find1(x.snd)){
			merge1(x.fst,x.snd);
			ans.pb({x.fst,x.snd,1});
		}
	}
}


int main(){
	fastio;
	cin>>n>>m>>k;

	frr(i,n){
		id1[i]=id2[i]=i;
		sz1[i]=sz2[i]=1;
	}

	int a,b,c;
	fr(i,m){
		cin>>a>>b>>c;
		if(c)
			tp2.pb({a,b});
		else
			tp1.pb({a,b});
	}
	kruskal();

	if(ans.size()!=(n-1) || k!=0)
		cout<<"no solution"<<endl;
	else
		for(auto x:ans)
			cout<<get<0>(x)<<' '<<get<1>(x)<<' '<<get<2>(x)<<endl;


}
