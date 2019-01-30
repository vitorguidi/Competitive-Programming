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

int v[1010];
int ans[1010];

bool check(int n){

	for(int i=0;i<n-1;i++){
		if(i%2==1 && v[i+1]<v[i])	return false;
		if(i%2==0 && v[i+1]>v[i])	return false;
	}

	return true;

}

int main(){
    
	fastio;

	int n; cin >> n;

	fr(i,n)	cin >> v[i];

	sort(v,v+n);

	int ini = 0;
	int end = n-1;

	int amt=n;

	int cnt = 0;

	while(ini<=end && amt){
		if(cnt%2==0){
			ans[cnt]=v[ini++];
			cnt++;
		}
		else{
			ans[cnt]=v[end--];
			cnt++;
		}
		amt--;
	}

	// if(!check(n)){
	// 	puts("Impossible");
	// 	return 0;
	// }

	fr(i,n)
		cout << ans[i] << " ";
	gnl;

}

