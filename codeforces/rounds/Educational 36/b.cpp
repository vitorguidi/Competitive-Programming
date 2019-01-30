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

int main(){
    
	fastio;

	int n,pos,l,r;
	cin >> n >> pos >> l >> r;

	if(l==1 && r==n){
		cout << 0 << endl;
		return 0;
	}

	int ans = INF;

	int ans1=0;
	int pos1=pos;

	if(l>1){
		ans1+=abs(pos1-l)+1;
		pos1=l;
	}

	if(r<n){
		ans1+=abs(pos1-r)+1;
		pos1=r;
	}

	ans=min(ans1,ans);

	int ans2=0;
	int pos2=pos;


	if(r<n){
		ans2+=abs(pos2-r)+1;
		pos2=r;
	}

	if(l>1){
		ans2+=abs(pos2-l)+1;
		pos2=l;
	}

	ans = min(ans,ans2);

	cout << ans << endl;

}

