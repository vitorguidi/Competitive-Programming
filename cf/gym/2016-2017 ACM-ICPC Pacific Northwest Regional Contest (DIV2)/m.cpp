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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[55];int n; 
int memo[55][55][2];

int pd(int ind,int last,int x){		//x=0 quero cara menor, x=1 quero cara mairo

	if(ind>n)
		return 0;

	int &pdm=memo[ind][last][x];
	
	if(pdm!=-1)
		return pdm;

	pdm=0;

	pdm=max( pdm , pd(ind+1,last,x) );

	int num=v[ind];

	if(num>last && x==1)
		pdm=max( pdm , 1+pd(ind+1,num,0) );
	
	if(num<last && x==0)
		pdm=max( pdm, 1+pd(ind+1,num,1) );

	return pdm;

}

int main(){
    
	cin >> n;

	frr(i,n)
		cin >> v[i];

	ms(memo,-1);
	cout << max(pd(1,52,0),pd(1,0,1)) << endl;  

}

