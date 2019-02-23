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

ll x,y,xini,yini;
string s;
ll len;

ll acumh[100100],acumv[100100];

ll check(ll val){

	ll old_val=val;

	ll ciclos = val/len;

	ll wv = ciclos*acumv[len];
	ll wh = ciclos*acumh[len];

	val-=ciclos*len;

	wv+= acumv[val];
	wh+= acumh[val];


	ll xnow = xini+wh;
	ll ynow = yini+wv;

	ll falta = abs(y-ynow)+abs(x-xnow);
	return falta<=old_val;

}

int main(){
    
	fastio;

	cin >> xini >> yini >> x >> y;

	if(x==xini && y==yini){
		cout << 0 << endl;
		return 0;
	}

	cin >> len >> s;

	frr(i,len){
		char k = s[i-1];
		if(k=='U')	acumv[i]++;
		if(k=='D')	acumv[i]--;
		if(k=='R')	acumh[i]++;
		if(k=='L')	acumh[i]--;
		acumv[i]+=acumv[i-1];
		acumh[i]+=acumh[i-1];
	}

	ll ini=1;
	ll end=1e15;

	ll best=llINF;

	while(ini<=end){

		ll mid = (ini+end)/2ll;

		if(check(mid)){
			end=mid-1ll;
			best=min<ll>(best,mid);
		}
		else
			ini=mid+1;

	}

	cout << (best==llINF? -1 : best) << endl;

}

