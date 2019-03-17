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

int v[10];

int main(){
    
	fastio;

	int n; cin >> n;

	fr(i,n){
		int x; cin >> x;
		v[i%3]+=x;
	}

	vector<pii> aux;
	if(v[0]>v[1] && v[0]>v[2])	puts("chest");
	else if(v[1]>v[0] && v[1]>v[2])	puts("biceps");
	else	puts("back");

}