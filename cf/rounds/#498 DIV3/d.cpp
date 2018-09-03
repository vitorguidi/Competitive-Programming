#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

int main(){

	int n; cin >> n;
	string a,b;
	getline(cin,a);
	getline(cin,a);
	getline(cin,b);

	int ans=0;

	fr(i,(n+1)/2){

		vector<char> tempa,tempb;
		tempa.pb(a[i]);
		tempb.pb(b[i]);
		
		if(n-1-i>i){
			tempb.pb(b[n-1-i]);
			tempa.pb(a[n-1-i]);
		}

		sort(all(tempa));
		sort(all(tempb));
		
		if(tempa.size()==1){
			if(tempa[0]!=tempb[0])
				ans++;
		}
		else{
			if(tempa[0]==tempb[0] && tempa[1]==tempb[1])
				continue;
			else if(tempa[0]==tempb[0] && tempa[1]!=tempb[1])
				ans++;
			else if(tempa[0]!=tempb[0] && tempa[1]==tempb[1])
				ans++;
			else{
				set<char> se({tempa[0],tempb[0],tempa[1],tempb[1]});
				if(se.size()==4)
					ans+=2;
				else if(se.size()==3){
					ans++;
					if(tempa[0]==tempa[1])
						ans++;
				}
			}
		}

		// fr(i,tempa.size())
		// 	cout << tempa[i] << " ";
		// gnl;
		// fr(i,tempb.size())
		// 	cout << tempb[i] << " ";
		// gnl;
		// gnl;

	}

	cout << ans << endl;

}