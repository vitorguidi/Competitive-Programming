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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
string s;
int x,y;

int u[200200], d[200200], r[200200], l[200200];

bool check(int mid){

	bool flag = false;

	for(int i=1;i+mid-1<=n;i++){

		int a=0,b=0;

		a+=r[n];
		a-=l[n];
		b+=u[n];
		b-=d[n];

		a-=r[i+mid-1]-r[i-1];
		a+=l[i+mid-1]-l[i-1];
		b-=u[i+mid-1]-u[i-1];
		b+=d[i+mid-1]-d[i-1];

		ll dist = abs(x-a)+abs(y-b);

		if(mid>=dist && (mid-dist)%2==0)
			flag=true;

	}

	return flag;


}

int main(){

	fastio;

	cin >> n >> s >> x >> y;
	int dist = abs(x)+abs(y);

	s = '#'+s;

	if( dist>n || (n%2 != dist%2) ){
		cout << -1 << endl;
		return 0;
	}

	int xt=0,yt=0;

	for(int i=1;i<=n;i++){
	
		if(s[i]=='U'){
			u[i]++;
			yt++;
		}
		if(s[i]=='D'){
			d[i]++;
			yt--;
		}
		if(s[i]=='L'){
			l[i]++;
			xt--;
		}
		if(s[i]=='R'){
			r[i]++;
			xt++;
		}
		
		u[i]+=u[i-1];
		d[i]+=d[i-1];
		l[i]+=l[i-1];
		r[i]+=r[i-1];
	
	}

	if(xt==x && yt==y){
		cout << 0 << endl;
		return 0;
	}

	int ini=1, end=n;
	int best=INF;
	while(ini<=end){
		int mid = (ini+end)/2;
		if(check(mid)){
			best=min(best,mid);
			end=mid-1;
		}
		else
			ini=mid+1;
	}

	if(best!=INF)
		cout << best << endl;
	else
		cout << -1 << endl;


}