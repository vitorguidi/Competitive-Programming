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

typedef tuple<ll,ll,ll> tup;

tup v[212345];
int ans[212345];

int main(){

	fastio;
	int n; 
	cin>>n;

	int a,b,c;

	fr(i,n){
		cin>>a>>b; 
		get<0>(v[i])=b;
		get<1>(v[i])=a;
		get<2>(v[i])=1+i;
	}

	sort(v,v+n); 

	set<tup> q;

	ans[ get<2>(v[n-1]) ] = -1;

	b=get<0>(v[n-1]);
	a=get<1>(v[n-1]);
	c=get<2>(v[n-1]);

	q.insert({a,b,c});

	for(int i=n-2;i>=0;i--){
	
		b=get<0>(v[i]);
		a=get<1>(v[i]);
		c=get<2>(v[i]);

		q.insert({a,b,c}); 

		auto it=q.find( {a,b,c} );

		if(it==q.begin()){
			it++;
			tup aux=*(it);
			ans[c]=get<2>(aux);
		}
		else if( q.upper_bound(*it)==q.end()){
			it--;
			tup aux=*(it);
			ans[c]=get<2>(aux);
		}
		else{
			tup aux,aux2;
			it--;
			aux=*(it);
			it++;it++; 
			aux2=*(it); 
			if( abs(a-get<0>(aux)) <  abs(a-get<0>(aux2)))
				ans[c]=get<2>(aux);
			else if( abs(a-get<0>(aux)) >  abs(a-get<0>(aux2)))
				ans[c]=get<2>(aux2);
			else{
				if(get<1>(aux) > get<1>(aux2))
					ans[c]=get<2>(aux);
				else 
					ans[c]=get<2>(aux2);		
			}
		}
		

	}

	frr(i,n)
			cout<<ans[i]<<' '; 
			
		gnl;

}