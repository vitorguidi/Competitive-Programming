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
typedef pair<double,double> point;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const double pi = acos(-1);

ll tempos[1010],dists[1010];
int m,n;

struct fraction{

	ll x,y;
	
	fraction(ll a, ll b){
		ll aux = __gcd(a,b);
		a/=aux;
		b/=aux;
		x=a;y=b;
	}
	
	
	bool operator==(fraction b){
		return x==b.x && y==b.y;
	}

	bool operator!=(fraction b){
		fraction a = fraction(x,y);
		return !(a==b);
	}
		

};


bool check(int ind){

	vector<ll> seqt,seqd;
	
	ll base = tempos[1];
	for(int i=1;i<=m;i++)
		seqt.pb(tempos[i]-base);	
		
	base = dists[ind];
	for(int i=ind;i<ind+n;i++)
		seqd.pb(dists[i]-base);
		
	fraction param = fraction(seqt[1]-seqt[0],seqd[1]-seqd[0]);
	
	for(int i=2;i<m;i++){
		fraction cara = fraction(seqt[i]-seqt[i-1],seqd[i]-seqd[i-1]);
		if(cara!=param)	return false;
	}
	return true;
	
}

int main(){

	fastio;

	cin >> m >> n;
	
	frr(i,m)	cin >> tempos[i];
	frr(j,n)	cin >> dists[j];
	
	vector<ll> passos;
	
	for(int i=2;i<=m;i++)
		passos.pb(tempos[i]-tempos[i-1]);
	
	for(int i=1;i<m;i++){
		ll ds = dists[i+1]-dists[i];
		ll dt = passos[0];
	
	}
	
	if(n<m){
		cout << 0 << endl;
		return 0;
	}
	
	set<ll> ans;
	
	for(int i=1;i<=n-m+1;i++)
		if(check(i))
			ans.insert(dists[i+1]-dists[i]);
			
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	gnl;
	

}