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

string s;
int v[2020];
pii memo[2020][2020];
int len;

pii operator+(pii a, pii b){
	pii aux;
	aux.fst=a.fst+b.fst;
	aux.snd=a.snd+b.snd;
	return aux;
}

pii pd(int l,int r){

	if(l<0 || l>=len || r<0 || r>=len)
		return {0,0};

	pii &pdm=memo[l][r];
	if( pdm != mp(-1,-1) )
		return pdm;

	pii right = pd(l,r+1);
	pii left = pd(l-1,r);
	pii both = pd(l-1,r+1);

	if(r==l)
		return pdm=mp(v[l],1)+both;
	
	if(s[l]==s[r])
		pdm = mp(v[l]+v[r],2) + both;
	
	pdm = max(pdm,left);
	pdm = max(pdm,right);
	

	return pdm;

}

int main(){

	getline(cin,s);
	int  n; cin >> n;
	
	fr(i,n){
		int x;cin >> x;
		x--;
		v[x]=1;
	}

	fr(i,2020)
		fr(j,2020)
			memo[i][j]={-1,-1};

	pii ans = {0,0};
	len=s.size();

	fr(i,len)
		ans=max({ans,pd(i,i),pd(i,i+1)});

	
	cout << ans.snd << endl;

}