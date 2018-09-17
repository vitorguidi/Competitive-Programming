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

string x,y;
string ans;
int l1,l2;
vector<string> ans2;

void solve(int i, int j){

	if(i==l1 && j==l2){
		ans2.pb(ans);
		return;
	}

	if(i<l1){
		ans.pb(x[i]);
		solve(i+1,j);
		ans.pop_back();
	}

	if(j<l2){
		ans.pb(y[j]);
		solve(i,j+1);
		ans.pop_back();
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	int t;cin>>t;
	getline(cin,x);

	while(t--){
		
		ans.clear();
		ans2.clear();
		x.clear();
		y.clear();

		cin >> x;
		cin >> y;

		l1 = x.size();
		l2 = y.size();

		solve(0,0);
		map<string, int> check;

		sort(all(ans2));

		for(string lol : ans2){
			if(!check[lol]){
				cout << lol << endl;
				check[lol]=1;
			}
		}

		gnl;
    }

}
