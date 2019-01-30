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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	int n,k;
	cin >> n >> k;
	
	vii ans;

	fr(i,n){
		int x;
		cin >> x;
		ans.pb({x,i});
	}
	sort(all(ans));
	reverse(all(ans));

	int sum=0;
	
	fr(i,k)
		sum+=ans[i].fst;
	
	vi order;
	fr(i,k)
		order.pb(ans[i].snd);
	sort(all(order));


	int ini=0;
	cout << sum << endl;
	fr(i,k){
		if(i!=k-1)
			cout << order[i]-ini+1 << ' ';
		else
			cout << n-ini << " ";
		ini=order[i]+1;
	}
	gnl;




}

