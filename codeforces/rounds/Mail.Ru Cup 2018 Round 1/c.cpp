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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int l[1010];
int r[1010];
int ans[1010];

int main(){
    
	fastio;

	int n; cin >> n;
	
	frr(i,n)
		cin >> l[i];

	frr(i,n)
		cin >> r[i];

	frr(i,n)
		ans[i]=n-(l[i]+r[i]);

	frr(i,n){
		
		int to_l=0,to_r=0;
		
		for(int j=1;j<i;j++)
			to_l+=(ans[j]>ans[i]);
		
		for(int j=n;j>i;j--)
			to_r+=(ans[j]>ans[i]);

		if(to_l!=l[i] || to_r!=r[i]){
			puts("NO");
			return 0;
		}

	}

	cout << "YES" << endl;
	frr(i,n)
		cout << ans[i] << " ";
	gnl;
		

}

