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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector< pair<string,int> > prices;
int memo[100100][8];
int n; 

int pd(int ind, int mask){

	if(ind==n){
		if(mask==7)
			return 0;
		return INF;
	}

	int &pdm=memo[ind][mask];
	if(pdm!=-1) return pdm;

	pair<string, int> cara = prices[ind];
	int new_mask=mask;

	fr(i,cara.fst.size()){
		char letra = cara.fst[i];
		int num = letra-'A';
		new_mask = new_mask|(1<<num);
	}

	pdm=INF;
	pdm=min(pdm, cara.snd + pd(ind+1,new_mask) );
	pdm=min(pdm, pd(ind+1,mask));

	return pdm;


}

int main(){
    
	fastio;

	cin >> n;

	string s;getline(cin,s);

	fr(i,n){
		int x; cin >> x;
		cin >> s;
		sort(all(s));
		pair<string, int> aux;
		aux = mp(s,x);
		prices.pb(aux);

	}

	ms(memo,-1);
	int ans = pd(0,0);
	
	if(ans<INF)
		cout << ans << endl;
	else
		cout << -1 << endl;


}

