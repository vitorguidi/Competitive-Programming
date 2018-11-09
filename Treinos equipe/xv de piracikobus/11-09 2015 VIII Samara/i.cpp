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

int xc2,yc2;
string s;

int calc(int x, int y){

	int ans = 0;

	int xc=xc2;
	int yc=yc2;

	if(s=="LEFT"){

		ans+=(abs(y-yc)+1)/2;
		xc-=ans;

		if(x==xc)
			return ans;

		else if(x<xc)
			return ans+(abs(xc-x)+2)/3;

		else
			return ans+x-xc;

	}

	if(s=="RIGHT"){

		ans+=(abs(y-yc)+1)/2;
		xc+=ans;

		if(x==xc)
			return ans;

		else if(x<xc)
			return ans + xc - x;

		else
			return ans+(abs(xc-x)+2)/3;

	}

	if(s=="UP"){

		ans+=(abs(x-xc)+1)/2;
		yc+=ans;

		if(y==yc)
			return ans;

		if(y>yc)
			return ans + (abs(y-yc)+2)/3;

		if(y<yc)
			return ans+ yc - y;

	}

	if(s=="DOWN"){

		ans+=(abs(x-xc)+1)/2;
		yc-=ans;

		if(y==yc)
			return ans;

		if(y>yc)
			return ans+ y - yc;

		if(y<yc)
			return ans + (abs(y-yc)+2)/3;


	}

}

int main(){

	fastio;
	cin >> xc2 >> yc2 >> s;

	int n; cin >> n;

	int ans = INF;
	string cara = "null";

	fr(i,n){
		
		string nome;
		int x,y;
		
		cin >> nome >> x >> y;

		int dist = calc(x,y);

		if(dist<ans){
			cara = nome;
			ans=dist;
		}
	}	

	cout << cara << endl;

}
