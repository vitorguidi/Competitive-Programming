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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vi jedi[200200];
int mx1l[200200],mx1r[200200];
int mx2l[200200],mx2r[200200];
int good[200200];

int main(){

	fastio;

	int n; cin >> n;

	frr(i,n){
		int a,b,c;
		cin >> a >> b >> c;
		jedi[i]={a,b,c};
		sort(all(jedi[i]));
	}

	mx1l[0]=mx2l[0]=mx1r[n+1]=mx2r[n+1]=-INF;

	for(int i=1;i<=n;i++){
		mx1l[i]=max(mx1l[i-1],jedi[i][1]);
		mx2l[i]=max(mx2l[i-1],jedi[i][0]);
	}

	for(int i=n;i>0;i--){
		mx1r[i]=max(mx1r[i+1],jedi[i][1]);
		mx2r[i]=max(mx2r[i+1],jedi[i][0]);
	}

	int cnt =0;

	frr(i,n){
		if(jedi[i][2]<mx1l[i-1])	continue;
		if(jedi[i][2]<mx1r[i+1])	continue;
		if(jedi[i][1]<mx2l[i-1])	continue;
		if(jedi[i][1]<mx2r[i+1])	continue;
		good[i]++;
		cnt++;
	}

	cout << cnt << endl;

	frr(i,n)
		if(good[i])
			cout << i << " ";
	gnl;

}