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

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


ll n,m,x,pos,neg,sum;

int main(){
    
	cin >> n >> m;

	fr(i,m){
		ll aux1,aux2;
		cin >> aux1 >> aux2;
		x+=aux1;
		if(aux2>=0)
			pos+=aux2;
		else
			neg+=aux2;
	}

	ll mid = (n+1)/2;

	ll meio =0,ponta=0;
	frr(i,n)
		meio+=abs(mid-i);
	frr(i,n)	
		ponta+=abs(i-1);

	sum+=x*n;
	sum+=meio*neg;
	sum+=ponta*pos;

	double ans = sum;
	ans=ans/double(n);

	cout << setprecision(15) << fixed;
	cout << ans << endl;

}


