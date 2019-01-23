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
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9;
typedef tuple<ll,ll,ll,ll,ll> tup;
ll n,a,b;
vector<tup> teams;

int main(){

	fastio;
	cin>>n>>a>>b;
	while(n!=0){
		teams.clear();
		ll K,A,B;
		fr(i,n){
			cin>>K>>A>>B;
			teams.pb({abs(A-B) , max(mod-A,mod-B) , max(A,B) , (A>B)?0:1 , K});
		}
		sort(all(teams));
		ll sum=0;

		for(int i=teams.size()-1;i>=0;i--){
			tup aux=teams[i];
			ll need=get<4>(aux);
			ll quem=get<3>(aux);
			ll menor=mod-get<1>(aux);
			ll maior=get<2>(aux);

			ll pego;
			if(quem){
				if(a!=0){
					pego=min(need,a);
					a-=pego;
					need-=pego;
					sum+=pego*menor;
					if(need!=0){
						b-=need;
						sum+=need*maior;
					}
				}
				else{
					b-=need;
					sum+=need*maior;
				}
			}
			else{
				if(b!=0){
					pego=min(need,b);
					b-=pego;
					need-=pego;
					sum+=pego*menor;
					if(need!=0){
						a-=need;
						sum+=need*maior;
					}
				}
				else{
					a-=need;
					sum+=need*maior;
				}

			}

		}

		cout<<sum<<endl;


		cin>>n>>a>>b;
	}

}