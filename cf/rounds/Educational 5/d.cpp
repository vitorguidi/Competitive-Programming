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

int v[500500];
int n,k;
map<int,int> freq;

int main(){
    
	fastio;

	cin >> n >> k;

	fr(i,n)	cin >> v[i];

	int ini=0;
	int end = 0;
	int cnt = 0;

	int l=-2;
	int r = -1;
	int best = 0;

	while(ini<n){

		while(end<n && (cnt + (freq[v[end]]==0)<=k) ){
			cnt+=(freq[v[end]]==0);
			freq[v[end]]++;
			end++;
		}

		if(end-ini>best){
			best=end-ini;
			l=ini;
			r=end-1;
		}

		freq[v[ini]]--;
		if(!freq[v[ini]])
			cnt--;

		ini++;

	}

	cout << l+1 << " " << r+1 << endl;

}