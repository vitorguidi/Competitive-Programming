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

int freq[200200];
vii v;

int main(){
    
	fastio;

	int n,k;
	cin >> n >> k;


	frr(i,n){
		int x; cin >> x;
		freq[x]++;
	}


	frr(i,200000)
		if(freq[i])
			v.pb({freq[i],i});

	sort(all(v));
	reverse(all(v));

	int best = 1;
	int ini=1;
	int end =n;

	while(ini<=end){
	
		int mid = (ini+end)/2;
	
		int cnt = 0;
	
		for(auto x : v)
			cnt+=x.fst/mid;
	
		if(cnt>=k){
			best=max(best,mid);
			ini=mid+1;
		}
		else
			end=mid-1;
	}

	vi ans;

	int amt = k;
	for(auto x : v){
		
		if(!amt)
			break;

		int pega = min(amt,x.fst/best);
		
		fr(i,pega)
			ans.pb(x.snd);

		amt-=pega;
	
	}

	sort(all(ans));

	for(auto x : ans)
		cout << x << " ";
	gnl;

}

