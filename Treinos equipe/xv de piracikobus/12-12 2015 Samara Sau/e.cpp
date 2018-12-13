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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vector < tuple <ll,ll,ll> > cards; 

int main(){

	fastio;

	int n;
	cin>>n; 

	int a,b;
	fr(i,n-1){

		cin>>a>>b;
		cards.pb(make_tuple(b,a,i+1));

	}

	sort(all(cards));

	int cost,i,j;
	vi path; 
	tuple <ll,ll,ll> best; 

	cin>>a>>b;

	cost=a;

	path.pb(n);

	i=j=n-2;

	while(i>=0 && cost > 1 ){

		while(get<0>(cards[j]) >= cost && j >= 0 )
			j--; 

		if(j==i) break; 

		get<1>(best)=llINF;

		while( i > j ){
			if(get<1>(cards[i]) < get<1>(best) )
				best=cards[i];
			i--;
		}

		if(get<1>(best)!=llINF){
			path.pb( get<2>(best) );
			cost=get<1>(best);
		}

	}


	if(cost>1)
		cout<<"No such luck"<<endl; 
	else{
		cout<<path.size()<<endl; 

		reverse(all(path));
		for(auto x:path)
			cout<<x<<' ';
		gnl;
	}


}


