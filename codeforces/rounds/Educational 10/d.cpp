#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << terml
#define all(x)	x.begin(),x.end()

#define gnl cout << terml
#define olar cout << "olar" << terml
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int bit[900500];
int printa[900500];

void update(int ind, int val){
	for(int i=ind;i<900400;i+=i&-i)
		bit[i]+=val;
}

int query(int ind){
	int ans=0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int main(){
    
	fastio;

	int n; cin >> n;

	vector<tuple<int,int,int>> pairs;
	vi coord;

	fr(i,n){
		int x,y;
		cin >> x >> y;
		tuple<int,int,int> aux = make_tuple(x,y,i);
		pairs.pb(aux);
		coord.pb(x);
		coord.pb(y);
		coord.pb(y-1);
		coord.pb(x-1);
	}

	sort(all(pairs));
	sort(all(coord));

	map<int,int> id;
	int cnt=1;

	for(auto x : coord)
		if(!id[x])	id[x]=cnt++;
	
	fr(i,n){
		tuple<int,int,int>& cara = pairs[i];
		get<0>(cara)=id[get<0>(cara)];
		get<1>(cara)=id[get<1>(cara)];
	}


	for(auto x : pairs)
		update(get<1>(x),1);

	for(auto x : pairs){

		printa[get<2>(x)]= query(get<1>(x)) - query(get<0>(x)-1);	
		update(get<1>(x),-1);
	
	}

	fr(i,n)
		cout << printa[i]-1 << endl;

}

