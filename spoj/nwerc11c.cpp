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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int bit[200200];
int pos[200200];

void update(int ind, int val){
	for(int i=ind;i<200200;i+=i&-i)
		bit[i]+=val;
}

int query(int ind){
	int ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

void solve(){

	ms(bit,0);

	int n,q; cin >> n >> q;

	frr(i,n){
		pos[i]=n-i+1;
		update(pos[i],1);
	}

	int top = n;

	fr(i,q){
		int id; cin >> id;
		int amt = n-query(pos[id]);
		cout << amt << " ";
		update(pos[id],-1);
		pos[id]=++top;
		update(pos[id],1);
		
		
	}
	gnl;

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();
}