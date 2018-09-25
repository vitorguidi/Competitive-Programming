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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
	map<int,int> m;
	int v[100100];

	int t;
	cin >> t;

	while(t--){
	
		int n,q;
		cin >> n >> q;

		m.clear();

		int amt=0;

		frr(i,n){
			cin >> v[i];
			if(m[v[i]]==0 && v[i])
				amt++;
			m[v[i]]++;
		}

		frr(i,q){
			
			int op; 
			cin >> op;

			if(op==2){
				cout << amt << endl;
				continue;
			}

			int x,y;
			cin >> x >> y;

			if(m[v[x]]==1 && v[x])
				amt--;
			m[v[x]]--;

			if(m[y]==0 && y)
				amt++;
			m[y]++;

			v[x]=y;

		}
	}

}