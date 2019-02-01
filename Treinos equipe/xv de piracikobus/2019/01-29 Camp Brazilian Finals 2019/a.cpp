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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
map<int,int> ling;
int id[101];
int sz[101];

int find (int a){
	if(id[a] == a) return a;
	else return find(id[a]);
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(sz[a] > sz[b]) swap(a,b);
	id[a] = b;
	sz[b] += sz[a];
}

int main(){

	fastio;
	int n,m;
	cin >> n >> m;
	frr(i,n){
		id[i] = i;
		sz[i] = 1;
	}
	int ct = 0;
	frr(i,n){
		int a;
		cin >> a;
		fr(j,a){
			int b;
			cin >> b;
			if(ling[b] == 0){
				ling[b] = i;
			}
			//dbg(ling[b]);
			merge(i,ling[b]);
		}
		if(a == 0) ct++;
	}

	set<int> s;

	frr(i,n){
		s.insert(find(i));
	}

	if (ct== n) s.insert(-4);

	cout << s.size() - 1 << endl;


}
