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

int v[110];
int n; 

int go(int x){

	int ans = 0;

	frr(i,n){
		int tmp=0;
		tmp+=2*(abs(x-1)+abs(x-i)+abs(i-1));
		tmp*=v[i];
		ans+=tmp;
	}

	return ans;

}

int main(){
    
	fastio;

	cin >> n;
	frr(i,n)	cin >> v[i];

	int ans = INF;

	frr(i,n)	ans=min(ans,go(i));

	cout << ans << endl;

}