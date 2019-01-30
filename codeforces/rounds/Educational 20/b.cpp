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

int l[200100];
int r[200100];
int v[200100];

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n)	cin >> v[i];

	l[0]=-INF;
	l[n+1]=INF;

	for(int i=n;i>0;i--){
		if(v[i]==0)	r[i]=i;
		else		r[i]=r[i+1];
	}

	for(int i=1;i<=n;i++){
		if(v[i]==0)	l[i]=i;
		else		l[i]=l[i-1];
	}

	frr(i,n){
		int dl = abs(l[i]-i);
		int dr = abs(r[i]-i);
		cout << min(dl,dr) << " ";
	}
	gnl;

}

