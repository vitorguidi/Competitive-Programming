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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

string mask(int x){
	stack<int> s;
	do{
		if(x%10==4  || x%10==7)
			s.push(x%10);
		x/=10;
	}while(x!=0);
	string ans;
	while(!s.empty()){
		ans.pb(s.top()+'0');
		s.pop();
	}
	return ans;
}

int main(){
    
	fastio;

	int a,b;
	cin >> a >> b;

	int ini = a+1;

	while(true){
		if(mask(ini)==mask(b)){
			cout << ini << endl;
			return 0;
		}
		ini++;
	}


	

}