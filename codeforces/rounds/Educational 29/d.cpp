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
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[200200];

int reverse_swap(int ind, int l, int r){

	int old_l=l;
	int old_r=r;

	int offset = l-1;

	r-=offset;
	l-=offset;
	ind-=offset;

	ind=r+1-ind;
	ind+=offset;

	return ind;

}

int reverse_shift(int ind, int l, int r){

	if(ind==l)
		return r;

	return ind-1;

}

int main(){
    
	fastio;

	int n,q,m;

	vi good;

	cin >> n >> q >> m;

	frr(i,n)	cin >> v[i];


	vector< tuple<int,int,int> > queries;

	fr(i,q){
		int op,l,r;
		cin >> op >> l >> r;
		tuple<int,int,int> aux;
		get<0>(aux)=op;
		get<1>(aux)=l;
		get<2>(aux)=r;
		queries.pb(aux);
	}

	reverse(all(queries));


	fr(i,m){
		int x; cin >> x; good.pb(x);
	}

	fr(i,m){

		int ind = good[i];

		for(auto x : queries){

			if(get<1>(x)>ind || get<2>(x)<ind)	continue;

			if(get<0>(x)==1)
				ind=reverse_shift(ind,get<1>(x),get<2>(x));
			else
				ind=reverse_swap(ind,get<1>(x),get<2>(x));
		}

		cout << v[ind] << " ";
	}

	gnl;

}

