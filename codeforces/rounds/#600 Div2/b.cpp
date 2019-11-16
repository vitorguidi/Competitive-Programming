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

int v[100100];

int main() {

	int n;
	cin >> n;
	
	fr(i,n)
		cin >> v[i];

	map<int,int> vis;
	map<int,int> tira;
	int open=0;
	int ev=0;
	vi ans;

	for(int i=0;i<n;i++){
		
		ev++;
		int ind = abs(v[i]);

		if(v[i]>0){
			if(vis[ind]){
				cout << -1 << endl;
				return 0;
			}
			vis[ind]++;
			open++;
		}
		
		else{
			if(!vis[ind] || tira[ind]){
				cout << -1 << endl;
				return 0;
			}
			open--;
			tira[ind]++;
		}
		if(open==0){
			vis.clear();
			ans.pb(ev);
			tira.clear();
			ev=0;
		}
	}

	if(open!=0){
		cout << -1 << endl;
		return 0;
	}

	cout << ans.size() << endl;
	for(auto x : ans)	cout << x << " ";
	gnl;
	
}
