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

int id[200200];
int v[200200];

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	id[b]=a;
}

int main(){

	fastio;

	int n; cin >> n;

	frr(i,n)	id[i]=i;

	frr(i,n)	cin >> v[i];

	int k; cin >> k;

	fr(i,k){

		frr(j,n){
			int x; cin >> x;
			join(j,x);
		}

	}

	int cara;	cin >> cara;
	int pos = -1;

	frr(i,n)
		if(v[i]==cara)
			pos=i;

	if(find(1)==find(pos))	puts("YES");
	else					puts("NO");

}
