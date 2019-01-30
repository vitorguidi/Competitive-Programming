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
const ll llINF = 0x3f3f3f3f3f3f3f;

char v[110][110];
int n,m;

bool check(){	//checa a flag horizontalmente. depois checa transposta

	

	// fr(i,n){
	// 	fr(j,m)
	// 		cout << v[i][j];
	// 	gnl;
	// }
	// gnl;gnl;gnl;

	fr(i,n)
		fr(j,m-1)
			if(v[i][j]!=v[i][j+1])
				return false;

	string aux;

	fr(i,n)	aux.pb(v[i][0]);

	vi cnta,cntb,cntc;

	fr(i,n){
		if(v[i][0]=='R')	cnta.pb(i);
		if(v[i][0]=='B')	cntb.pb(i);
		if(v[i][0]=='G')	cntc.pb(i);
	}

	int lena=cnta.size();
	int lenb=cntb.size();
	int lenc=cntc.size();

	if(!lenc || !lena || !lenb)
		return false;

	if(lena!=lenb || lena!=lenc || lenb!=lenc)
		return false;

	fr(i,lena-1)
		if(cnta[i]!=cnta[i+1]-1)	return false;
	

	fr(i,lenb-1)
		if(cntb[i]!=cntb[i+1]-1)	return false;

	fr(i,lenc-1)
		if(cntc[i]!=cntc[i+1]-1)	return false;

	return true;


}

int main(){
    
	fastio;

	cin >> n >> m;

	fr(i,n)
		fr(j,m)
			cin >> v[i][j];

	bool ans = false;

	ans|=check();

	int aux = max(n,m);

	for(int i=0;i<aux;i++)
		for(int j=i;j<aux;j++)
			swap(v[i][j],v[j][i]);

	swap(n,m);

	ans|=check();

	cout << (ans ? "YES" : "NO" ) << endl;

}

