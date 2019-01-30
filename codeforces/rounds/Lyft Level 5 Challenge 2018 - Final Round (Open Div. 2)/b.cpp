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

ll id[200200];
ll v[200200];
vector<ll> drivers;
ll freq[200200];
map<ll,ll> cara;

int main(){
    
	fastio;

	ll n,m; cin >> n >> m;

	fr(i,n+m) cin >> v[i];		//residencia de cada um

	int cnt = 0;

	fr(i,n+m){
	
		cin >> id[i];		//eh ou nao driver
	
		if(id[i]){
			drivers.pb(v[i]);	//coordenada da casa do cnt-esimo driver
			cara[v[i]]=cnt++;	//id de driver do cara q mora na casa tal
		}

	}

	fr(i,n+m){

		if(id[i])	continue;
		
		auto right = upper_bound(all(drivers),v[i]);
		auto left = right; left--;

		ll dr=llINF;
		ll dl=llINF;

		if(right!=drivers.end())	dr=*right;
		if(*left<v[i])				dl=*left;

		int ans;
		if(abs<ll>(v[i]-dl)<=abs<ll>(v[i]-dr))
			ans=dl;
		else
			ans=dr;

		freq[cara[ans]]++;

	}

	fr(i,m)
		cout << freq[i] << " ";
	gnl;



}