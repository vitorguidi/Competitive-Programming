#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define priority_queue pq
#define grtp greater<pair<int,int>

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

	int n,k,aux;
	vector<int> seq;

	cin >> n >> k;
	fr(i,n){
		cin >> aux;
		seq.push_back(aux);
	}

	sort(all(seq));

	int cnt=0;

	if(k==0){
		if(seq[0]==1){
			cout << -1 << endl;
			return 0;
		}
		cout << seq[0]-1 << endl;
		return 0;
	}

	if(k==n){
		cout << seq[n-1] << endl;
		return 0;
	}

	for(int i=seq[k-1];i<seq[k];i++){
			cout<<i<< endl;
			return 0;
	}
	cout << -1 << endl;
	
}
 