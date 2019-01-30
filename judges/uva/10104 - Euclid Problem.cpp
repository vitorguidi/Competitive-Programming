#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+9;

int euclid(int a, int b, int& x, int& y){

	if(b==0){
		x=1;y=0;
		return a; 
	}

	int x1,y1;

	int d = euclid(b,a%b,x1,y1);

	x = y1;
	y = x1 - (a/b)*y1;

	return d;

}

int main(){



	int a,b;

	while(cin >> a && cin >> b){

		int x,y;
		int gcd = euclid(a,b,x,y);

		cout << x << " " << y << " " << gcd << endl;

	}

}