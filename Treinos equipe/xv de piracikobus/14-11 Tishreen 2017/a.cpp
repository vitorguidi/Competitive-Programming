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


ll cnt_digit( ll num){
	int ans=0; 
	while(num!=0){
		ans++; 
		num /=10;

	}
	return (ans);
}
ll gen_9(int n){
	ll num=0,aux=9;
	frr(i,n){
		num +=aux; 
		aux *=10;
	} 
	return num;

}

void solve(){
	ll x,n,tot,nd; 
	cin>>n>>x; 
	bool ok=0;
	nd=cnt_digit(x);
	tot=0; 

	while(!ok){
		ll aux=gen_9(nd); 
		
		if(n > (aux-x+1)*nd ){
			tot+= aux - x+1;
			n-=(aux-x+1)*nd;
		} 
		else{
			if(n%nd){
				cout<<-1<<endl;
				return ;
			} 
			else{
				tot+= n/nd;
				cout<<tot<<endl; 
				return;
			}
		}

	x=aux+1; 
	nd++;

	}

}

int main(){
	int t; 
	cin>>t; 
	while(t--) solve();
}