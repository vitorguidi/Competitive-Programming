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

void solve(){
	vector<string> v,s; 
	int n;
	string c;

	cin>>n; 
	fr(i,n){
		cin>>c; 
		v.pb(c);
	}

	fr(i,n){
		cin>>c; 
		s.pb(c);
	}
	set<string> q; 
	ll cnt=0;
	vi tot;
	fr(i,n){
		if(q.find(v[i])!=q.end())
			q.erase(v[i]);
		else
			q.insert(v[i]);

		if(q.find(s[i])!=q.end())
			q.erase(s[i]);
		else
			q.insert(s[i]);

		if(q.size()==0){
			cnt++; 
			tot.pb(cnt);
			cnt=0;
		}
		else{
			cnt++;
		}
	}	
	fr(i,tot.size())
		cout<<tot[i]<<' ';
	gnl;	

}


int main(){

	fastio;
	int t; 
	cin>>t; 
	while(t--) solve();
}
