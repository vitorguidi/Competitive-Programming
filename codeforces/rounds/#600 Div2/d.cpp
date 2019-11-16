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

int id[200200],sz[200200],mx[200200];

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
	mx[a]=max(mx[a],mx[b]);
}

int main() {

	int n,m;
	cin >> n >> m;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
		mx[i]=i;
	}

	fr(i,m){
		int a,b;
		cin >> a >> b;
		join(a,b);
	}

	int cnt =0;

	for(int i=1;i<=n;){
		int to = mx[find(i)];
		for(int j=i+1;j<=to;j++){
			if(find(i)!=find(j)){
				join(i,j);
				cnt++;
				to=mx[find(i)];
			}
		}
		i=to+1;
	}

	cout << cnt << endl;

}
