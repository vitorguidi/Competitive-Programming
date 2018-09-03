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

ll n,b;

ll calc(ll k){
	return 4*k*(n-k);
}

int main(){

	cin >> n >> b;

	ll ini=1;
	ll end = n/2;	
	ll mid;
	ll k=0;

	if(n==1){
		cout << "1 1" << endl;
		return 0;
	}

	frr(i,100){
		
		mid = (ini+end)/2;	
		
		if(calc(mid)>b)
			end=mid-1;
		
		else if(calc(mid)<b){
			k=max(k,mid);
			ini=mid+1;
		}
		
		else{
			k=mid;
			break;
		}
	
	}

	ll left = b - calc(k);
	ll lado = n-2*k;

	if(!left){
		cout << k+1 << " " << k << endl;
		return 0;
	}

	if(left && lado==1){
		cout << k+1 << " " << k+1 << endl;
		return 0;
	}

	ll cx = k+1;
	ll cy = k+1;

	left--;
	

	if(left<lado-1){
		cy+=left;
		left=0;
	}
	else{
		cy+=lado-1;
		left-=lado-1;
	}

	if(left<lado-1){
		cx+=left;
		left=0;
	}
	else{
		cx+=lado-1;
		left-=lado-1;
	}

	if(left<lado-1){
		cy-=left;
		left=0;
	}
	else{
		cy-=lado-1;
		left-=lado-1;
	}

	if(left<lado-2){
		cx-=left;
		left=0;
	}

	else{
		cx-=lado-2;
		left=0;
	}

	cout << (int)cx << " " << (int)cy << endl;


}