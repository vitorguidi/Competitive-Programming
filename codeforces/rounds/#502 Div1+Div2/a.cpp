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

bool comp(pii a, pii b){

	if(a.fst>b.fst)	return true;
	else if(a.fst==b.fst)	return a.snd<b.snd;
	return false;

}

int main(){
    
	fastio;

	vii aux;

	int n; cin >> n;

	fr(i,n){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int sum = 0;
		sum+=a+b+c+d;
		aux.pb({sum,i});
	}

	sort(all(aux),comp);

	int cnt=1;
	for(auto x : aux){
		if(x.snd==0){
			cout << cnt << endl;
			return 0;
		}
		cnt++;
	}	

}

