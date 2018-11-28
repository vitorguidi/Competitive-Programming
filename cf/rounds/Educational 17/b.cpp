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

	ll nusb,nps2,nboth;
	cin >> nusb >> nps2 >> nboth;

	int n; cin >> n;

	vector< pair<ll,string> > caras;

	fr(i,n){
		ll x; string s;
		cin >> x >> s;
		caras.pb({x,s});
	}

	sort(all(caras));
	reverse(all(caras));

	int len=caras.size()-1;

	ll cnt=0;
	ll cost = 0;

	while( (nusb+nps2+nboth) && len>=0 ){

		if(caras[len].snd=="USB" && (nusb || nboth)){
			cost+=caras[len].fst;
			cnt++;
			if(nusb)	nusb--;
			else		nboth--;
		}

		else if(caras[len].snd=="PS/2" && (nps2 || nboth)){
			cost+=caras[len].fst;
			cnt++;
			if(nps2)	nps2--;
			else		nboth--;
		}

		len--;
		caras.pop_back();

	} 

	cout << cnt << " " << cost << endl;

}

