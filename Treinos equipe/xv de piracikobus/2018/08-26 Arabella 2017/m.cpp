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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

char nam[11];

int main(){
	
	fastio;
	cout << setprecision(6) << fixed;

	map<string, double> ref;
	int t; 
	scanf("%d",&t);

	while(t--){

		int n,c;
		scanf("%d%d",&c,&n);;

		int cnt=1;
	
		ref.clear();
		ref["JD"]=1.0;
	
		fr(i,c){
			double val;
			scanf("%s%lf",nam,&val);
			ref[nam]=val;
		}

		double ans = 0;

		fr(i,n){
			double val;			
			scanf("%lf%s",&val,nam);
			ans+=val*ref[nam];
		}

		cout << ans << endl;

	}

	return(0);

}