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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int v[101];
int id[101],sz[101];
int n;

int find(int x){
	if(x==id[x])	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	sz[a]+=sz[b];
	id[b]=a;
}

ll go(set<ll>& s){

	ll ans = 1;

	for(auto x : s)		ans= (ans*x)/__gcd(ans,x);

	return ans;

}

int main(){
    
	fastio;

	cin >> n;
	frr(i,n)	cin >> v[i];

	frr(i,n){
		sz[i]=1;
		id[i]=i;
	}

	set<ll> s;

	frr(i,n)	s.insert(v[i]);

	if(s.size()!=n){
		cout << -1 << endl;
		return 0;
	}

	frr(i,n)	join(i,v[i]);	


	s.clear();

	frr(i,n){
		int coiso = sz[find(i)];
		if(coiso%2)	s.insert(coiso);
		else		s.insert(coiso/2);
	}

	cout << go(s) << endl;


}