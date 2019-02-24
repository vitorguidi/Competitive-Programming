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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

struct point{
	ll x,y,z;
	point operator-(point p)	{return{ x-p.x, y-p.y, z-p.z};}
	point operator^(point p)	{return {y*p.z - z*p.y,
										 z*p.x - x*p.z,
										 x*p.y - y*p.x
										};
								}	
	ll operator*(point p)		{return x*p.x + y*p.y + z*p.z;}
	bool operator==(point p)	{return p.x==x && p.y==y && p.z==z;}

};

ll mixed(point a, point b, point c, point d){
	a=a-d;b=b-d;c=c-d;
	a=a^b;
	return a*c;
}

void solve(){

	int n;
	scanf("%d",&n);
	vector<point> v;
	
	fr(i,n){
		point p;
		scanf("%lld %lld %lld",&p.x,&p.y,&p.z);
		v.pb(p);
	}

	int best = 0;
	int planes = 0;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
	
				point dot = (v[i]-v[j])^(v[i]-v[k]);
				if(!(dot*dot))	continue;
				planes++;	

				int tmp=0;			

				for(auto x : v)	tmp+=  mixed(x,v[i],v[j],v[k])==0;
				best=max(best,tmp);	

			}
		}
	}

	if(!planes){printf("%d\n",n);return;}
	printf("%d\n",best);

}

int main(){

	
	int t; 
	scanf("%d",&t);
	while(t--)	solve();	

} 