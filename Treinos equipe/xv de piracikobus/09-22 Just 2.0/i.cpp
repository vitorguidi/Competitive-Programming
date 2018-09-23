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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int raiz(int x){
	int i;
	for(i=1;;i++)
		if(i*i==x)
			return i;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,v[112];
	cin>>n; 
	fr(i,n)
		fr(j,n){
			cin>>m;
			if(i==j)
				v[i]=m;
		}
	fr(i,n)
		cout<<raiz(v[i])<<" ";
    gnl;

}