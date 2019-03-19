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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int l1[10100],c1[10100];
int c2[10100],r2[10100];

int d1[10100],d2[10100];

int dfs1(int v){

	if(v==0)
		return 0;

	d1[v]=1+dfs1(c1[v]);
	dfs1(l1[v]);

	return d1[v];

}

int dfs2(int v){

	if(v==0)
		return 0;

	d2[v]=1+dfs2(c2[v]);
	dfs2(r2[v]);

	return d2[v];

}

int main(){

	int n1;

	cin >> n1;
	frr(i,n1){
		int x,l,c;
		cin >> x >> l >> c;
		l1[x]=l;
		c1[x]=c;
	}

	int n2;
	cin >> n2;
	frr(i,n2){
		int x,c,r;
		cin >> x >> c >> r;
		c2[x]=c;
		r2[x]=r;
	}

	dfs1(1);
	dfs2(1);

	int aux1=0;
	int aux2=0;

	for(int i=1;i<=n1;i++)
		aux1=max(aux1,d1[i]);
	for(int i=1;i<=n2;i++)
		aux2=max(aux2,d2[i]);


	int lol = max( min(d1[1],aux2), min(d2[1],aux1)  );

	cout << n2+n1-lol << endl;

}