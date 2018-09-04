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

ll masks[22];
int n,m;
ll gold=0;

void printa(int x){

	fr(i,n){
		if( x&(1<<i) )
			cout << i+1 << " ";
	}
	gnl;

}

bool check(int x){
	
	ll lol = 0;

	fr(i,n)
		if( x&(1<<i) )
			lol = lol | masks[i];
		
	return lol==gold;

}

int conta(int x){

	int len = 0;

	fr(i,n){
		if( x & (1<<i) )
			len++;
	}

	return len;

}

int main(){
    
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    fastio;
    
	cin >> n >> m;
	
	fr(i,m)
		gold = gold | (1ll <<i );

	fr(i,n){
		
		int k; cin >> k;
		
		ll tempo = 0;
		
		frr(j,k){
			int aux; cin >> aux;
			aux--;
			tempo=tempo|(1ll<<aux);
		}
		
		masks[i]=tempo;
		
	}

	vii ans;
	
	pii otp = mp(INF,0);
	
	fr(i, (1<<n) ){
		
		if(check(i)){
			int len = conta(i);
			otp = min( mp(len,i) , otp );
		}
		
	}
	
	
	int mask = otp.snd;

	cout << otp.fst << endl;
	printa(mask);


}