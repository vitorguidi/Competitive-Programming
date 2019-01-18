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

int main(){
	fastio;
	int n,posi[11234];
	int maxx; 
	cin>>n; 
	fr(i,n)
		cin>>posi[i]; 
	sort(posi,posi+n);	
	maxx=0;
	fr(i,n-1){
		maxx=max(maxx,posi[i+1]-posi[i]);
	} 
	if(maxx%2)
		cout<<maxx/2<<".5"<<endl;
	else 
		cout<<maxx/2<<".0"<<endl;
	return 0;
}