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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
 	int n,m,x;
 	vi A;  
 	cin>>n;
 	fr(i,n){
 		cin>>x; 
 		A.pb(x);
 	}
 	sort(all(A));
 	cin>>m; 
 	fr(i,m){
 		cin>>x; 
 		auto it = lower_bound(A.begin(),A.end(),x);
 		if(it==A.end())
 			cout<<"Dr. Samer cannot take any offer :(."<<endl;
 		else 
 			cout<<*it<<endl;
 	}

}