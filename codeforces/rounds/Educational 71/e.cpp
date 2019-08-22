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
 
int main(){
 
	fastio;

	vi coiso;

	for(int i=1;i<=100;i++)
		coiso.pb(i<<7);

	cout << "? ";
	for(auto x : coiso)
		cout << x << " ";
	gnl;fflush(stdout);

	ll aux = (1<<7)-1;

	ll ans; cin >> ans;

	ll out = aux&ans;

	coiso.clear();
	for(int i=1;i<=100;i++)
		coiso.pb(i);

	cout << "? ";
	for(auto x : coiso)
		cout << x << " ";
	gnl;fflush(stdout);

	aux=aux<<7;

	cin >> ans;
	ans=aux&ans;
	out|=ans;

	cout << "! " << out << endl;
	fflush(stdout);
 
}