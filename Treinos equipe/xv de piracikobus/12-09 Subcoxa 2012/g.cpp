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

int n;
int v1[30];
int v2[30];
int id[30];
int bit[300];

void update(int ind, int val){
	for(int i=ind;i<300;i+=i&-i)
		bit[i]+=val;
}

int query(int ind){
	int ans=0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

void solve(){


	fr(i,n)	cin >> v1[i];
	
	int cnt=1;
	
	fr(i,n){
		cin >> v2[i];
		id[v2[i]]=cnt++;
	}
	
	fr(i,n)	v1[i]=id[v1[i]];

	ms(bit,0);

	int inv = 0;

	fr(i,n){
		inv+=query(100)-query(v1[i]);
		update(v1[i],1);
	}

	cout << inv << endl;



}

int main(){

	fastio;

	while(cin>>n){
		solve();
	}

}
