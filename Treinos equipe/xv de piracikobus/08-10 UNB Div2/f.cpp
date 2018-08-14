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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100; 

int dist[1123456],mdist[1123456];

int main(){
	fastio; 
	int n,i,uni; 
	cin>>n; 
	frr(i,n){
		cin>>uni;
		int aux; 
		aux=i-dist[uni]; 
		dist[uni]=i;
		if(mdist[uni]<aux) 
			mdist[uni]=aux; 
	}  
	fr(i,1123456){
		if(mdist[i] && mdist[i]< (n+1)-dist[i]){
			mdist[i]=(n+1)-dist[i];
		}
	}
	pii bst; 
	bst.fst=INF;
	bst.snd=0; 
	for(i=1;i<1123456;i++) 
		if(mdist[i] && mdist[i]<bst.fst ){
			bst.fst=mdist[i]; 
			bst.snd=i;
		}
	cout<<bst.fst<<' '<<bst.snd<<endl;	

	return 0;
}