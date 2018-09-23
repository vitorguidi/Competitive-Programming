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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
int v[1123456];
vector <pll> tip;
vi ans;
ll soma; 
int c,m;
int main(){
	int T;
	cin >> T;
	while(T--){
		ms(v,0);
		tip.clear();
		ans.clear();
		cin >> c >> m;
		soma = 0;
		
		fr(i,c){
			cin >> v[i];
			soma += v[i];
		}

		if(soma < m){
			cout << "Impossible" << endl;
			continue;
		}

		sort(v,v+c);
		
		int i = 0;
		
		while (i<c){
			pll a;
			a.snd = v[i];
			a.fst = 0;
			while (v[i] == a.snd && i<c){
				a.fst += v[i];
				i++;
			}
			tip.pb(a);
		}

		sort(all(tip));

		i = tip.size() - 1;
		soma = 0;

		while (soma < m){
			soma += tip[i].fst;
			ans.pb(tip[i].snd);
			i--; 
		}

		sort(all(ans));
		fr(i,ans.size())
			cout << ans[i] << ' ';
		gnl;

	}


}