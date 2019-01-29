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
int n,k;
int v[505];
bool memo[505][505][255];
bool vis[505][505][255];

bool pd (int ind,int val,int cand){
	

	if(val == 0 && cand == 0){
		return true;
	}
	
	if(ind == n) return false;
	
	if(val<0 || cand < 0) return false;

	bool& pdm = memo[ind][val][cand];
	if(vis[ind][val][cand] == true) return pdm;
	vis[ind][val][cand]= true;


	pdm = pd(ind + 1,val,cand);
	if(pdm) return pdm;

	if(pd(ind + 1,val - v[ind],cand) == 1) pdm = true;
	if(pdm) return pdm;
	if(pd(ind + 1,val - v[ind],cand - v[ind]) == 1) pdm = true;

	return pdm;
}

int main(){

	cin >> n >> k;

	fr(i,n) scanf("%d", v + i);

	set<int> s;

	for(int i = 0; i<= (k + 1)/2;i++){
		if(pd(0,k,i) == 1){
			s.insert(i);
			s.insert(k-i);
		}
	}

	cout << s.size() << endl;

	for(auto x : s){
		printf("%d ",x);
	}
	printf("\n");


}
