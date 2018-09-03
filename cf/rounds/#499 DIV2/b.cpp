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

map<int,int> check;
vi stuff;
int sum[110];
int cnt;

int bruta(int d){
	int ans = 0;
	frr(i,cnt)
		ans+=sum[i]/d;
	return ans;
}

int main(){
    
	int n,m; cin >> n >> m;
	
	fr(i,m){
		int aux; cin >> aux;
		stuff.pb(aux);
	}
	
	sort(all(stuff));

	cnt = 1;
	fr(i,stuff.size()){
		int num = stuff[i];
		if(!check[num])
			check[num]=cnt++;
		sum[check[num]]++;	
	}

	cnt--;
	int ans = 0;

	frr(i,100){
		if(bruta(i)>=n)
			ans=i;
	}

	cout << ans << endl;

}