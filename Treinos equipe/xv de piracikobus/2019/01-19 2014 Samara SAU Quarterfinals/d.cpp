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

map<int,int> q;
int v[112345];

int main(){
	fastio;
	int n,m;
	cin>>n;

	int x;
	bool ok=0;
	int cnt=0;

	frr(i,n){
		cin>>x;
		v[i]=x;

		q[x]++;
		if(q[x]==n)
			ok=1;
	}

	if(ok==1){
		cout<<0<<endl;
		return 0;
	}

	cin>>m;

	int a,b;
	fr(i,m){
		cnt++;
		cin>>a>>b;

		q[v[a]]--;
		v[a]=b;
		q[b]++;

		if(q[b]==n){
			cout<<cnt<<endl;
			return 0;
		}

	}
	cout<<-1<<endl;
}
