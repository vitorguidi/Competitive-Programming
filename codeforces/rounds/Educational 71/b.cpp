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
const int MOD = 1e9+7;

int a[55][55],b[55][55];
int n,m;

void tag(int i, int j){
	b[i][j]=1;
	b[i][j+1]=1;
	b[i+1][j]=1;
	b[i+1][j+1]=1;
}

bool check(int i, int j){
	return a[i][j]&a[i+1][j]&a[i][j+1]&a[i+1][j+1];
}

int main(){
 
	fastio;

	cin >> n >> m;

	frr(i,n)
		frr(j,m)
			cin >> a[i][j];

	vector<pii> ans;

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(check(i,j)){
				tag(i,j);
				ans.pb({i,j});
			}
		}
	}

	frr(i,n){
		frr(j,m){
			if(a[i][j]!=b[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << ans.size() << endl;

	for(auto x : ans)
		cout << x.fst << " " << x.snd << endl;

}