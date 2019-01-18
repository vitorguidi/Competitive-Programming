#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

int main(){
	int a,b,c;
	map <int,int> m;
	vector <int> v;
	cin >> a >> b >>c;

	int i;
	for (i=0;i<a;i++){
		int at;
		cin >> at;
		m[at]++;
	}
	for (i=0;i<b;i++){
		int at;
		cin >> at;
		m[at]++;
	}
	for (i=0;i<c;i++){
		int at;
		cin >> at;
		m[at]++;
		if (m[at] == 3){
			v.push_back(at);
		}
	}

	sort (all(v));
	for (i=0;i<v.size();i++){
		cout << v[i] <<' ';
	}

	cout << endl;

	return (0);

}
