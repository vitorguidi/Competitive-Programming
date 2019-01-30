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

vi pos;
int n,r;

int main(){
    
	fastio;
	
	cin >> n >> r;

	frr(i,n){
		int x; cin >> x;
		if(x)
			pos.pb(i);
	}

	if(!pos.size()){
		cout << -1 << endl;
		return 0;
	}

	int ini=1;
	int flag = 1;
	int cnt=0;

	int last = -1;

	while(ini<=n){

		int tgt = ini+r-1;

		auto it = upper_bound(all(pos),tgt);
		it--;

		if(it-pos.begin()<=last){
			flag=0;
			break;
		}
	
		int val = *it;
		
		if(val-(r-1)>ini){
			flag=0;
			break;
		}

		ini = val+r;
		cnt++;
		last=it-pos.begin();

	}

	cout << (flag==0 ? -1 : cnt) << endl;

}

