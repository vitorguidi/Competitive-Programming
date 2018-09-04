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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int freq[12];

ll solve(int x,int a, int b){
	return a*(x*x)+ b*x;
}

void add(ll x){

	int aux[12];
	ms(aux,0);

	while(x!=0){
		int dig = x%10;
		aux[dig]++;
		x=x/10;
	}

	int cnt=0;
	int dig=-1;
	
	fr(i,10){
		if(aux[i]>cnt)
			cnt=aux[i];
	}
	fr(i,10)
		if(aux[i]==cnt)
			freq[i]++;

}

int main(){

	fastio;
	int t; cin >> t;

	while(t--){

		int a,b,n;
		cin >> a >> b >> n;
		
		vector<ll> nums;
		ms(freq,0);

		int x=1;
		while(solve(x,a,b)<=n){
			nums.pb(solve(x,a,b));
			x++;	
		}

		fr(i,nums.size())
			add(nums[i]);

		if(!nums.size()){
			cout << -1 << endl;
			continue;
		}

		int dig=-1;
		int cnt=-1;

		fr(i,10){
			if(freq[i]>cnt){
				dig=i;
				cnt=freq[i];
			}
		}

		cout << dig << endl;

	}	

}