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

// int v[500500];
map<int,int> id;
int main(){
    
	fastio;

	int mid = 200000;
	int l=200000;
	int r=200001;

	int q; cin >> q;
	while(q--){
		
		char op;
		int x;
		cin >> op >> x;
		
		if(op=='L'){
			id[x]=l;
			l--;
		}
		else if(op=='R'){
			id[x]=r;
			r++;
		}
		else{
			int froml=abs(id[x]-l-1);
			int fromr=abs(r-id[x]-1);
			cout << min(fromr,froml) << endl;
		}
	}

	
}

