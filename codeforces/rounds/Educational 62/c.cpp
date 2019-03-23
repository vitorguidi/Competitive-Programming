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

multiset<ll> s;

int n,k;

int main(){
    
	fastio;

	cin >> n >> k;

	vector<pll> v;

	fr(i,n){
		ll t,b;
		cin >> t >> b;
		v.pb({b,t});
	}

	sort(all(v));


	ll sum = 0;
	ll resp = 0;

	if(k==1){
		for(auto x : v){
			resp=max(resp,x.fst*x.snd);
		}
		cout << resp << endl;
		return 0;
	}

	for(int i=n-1;i>=0;i--){

		if(s.size()<k-1){
			sum+=v[i].snd;
			s.insert(v[i].snd);
			resp=max(resp,v[i].fst*sum);
		}

		else{
			resp=max(resp,v[i].fst*(sum+v[i].snd));
			if(*s.begin()<v[i].snd){
				sum-=*s.begin();
				sum+=v[i].snd;
				s.erase(s.begin());
				s.insert(v[i].snd);
			}
		}

	}

	

	cout << resp  << endl;

}