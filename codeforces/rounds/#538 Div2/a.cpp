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

int main(){
    
	fastio;

	ll x,y,z;
	cin >> x >> y >> z;
	ll a,b,c;
	cin >> a >> b >> c;

	if(a<x){
		cout << "NO" << endl;
		return 0;
	}

	a-=x;

	if(a+b<y){
		cout << "NO" << endl;
		return 0;
	}

	int resto=0;

	int tira = min(a,y);

	a-=tira;

	if(tira<y)	b-=y-tira;


	if(a+b+c<z){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

}