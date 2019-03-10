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

int freq[100100];

int main(){
    
	fastio;

	set<int> s,q;

	int ans = 0;

	int n,m;
	cin >> n >> m;

	frr(i,m){

		int x; cin >> x;
		freq[x]++;
		if(freq[x]==1){
			s.insert(x);
			ans++;
		}

		if(ans==n){
			cout << 1;
			for(auto x : s){
				freq[x]--;
				if(freq[x])	q.insert(x);
				else		ans--;
			}
			swap(s,q);
		}
		else
			cout << 0;

	}


	gnl;
	

}