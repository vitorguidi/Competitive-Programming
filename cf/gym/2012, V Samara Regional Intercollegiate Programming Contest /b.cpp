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
const ll MOD = 998244353;

int grundy[50];
int mex[50];

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	grundy[0]=grundy[1]=0;

	for(int i=2;i<=40;i++){
		
		ms(mex,0);
		int ans = 0;
		
		for(int j=1;j<=i-1;j++)
			mex[ grundy[j]^grundy[i-j] ]=1;
		
		for(int j=0;j<=40;j++){
			if(!mex[j])
				break;
			ans++;
		}

		grundy[i]=ans;
	
	}

	int n; cin >> n;
	int ans=0;
	fr(i,n){
		int x; cin >> x;
		ans^=grundy[x];
	}
	if(!ans)
		puts("Mike");
	else
		puts("Constantine");

}