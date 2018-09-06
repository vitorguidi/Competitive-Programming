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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int s;
	
bool check(int i,int j){

	int x=s;

	int turn=0;
	while(x && x>=0){

		if(turn==0)
			x-=i;
		else
			x-=j;
		turn=(turn+1)%2;
	}

	return x==0;


}

int main(){
    
	cin >> s;

	vii ans;

	for(int i=2;i<s;i++){
		if(check(i,i-1))
			ans.pb(mp(i,i-1));
		if(check(i,i))
			ans.pb(mp(i,i));
	}    

	sort(all(ans));

	cout << s << ":" << endl;
	
	for(auto x : ans)
		cout << x.fst << "," << x.snd << endl;
	

}

