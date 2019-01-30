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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	fastio;

	string s;
	int n,p,q;

	cin >> n >> p >> q;

	cin >> s;

	fr(i,100){
		fr(j,100){
			if(p*i+q*j==n){
				
				cout << i+j << endl;
				
				int amtp=i;
				int amtq=j;

				vector<string> ans;

				fr(k,amtp){
					int cnt=p;
					string aux;
					while(cnt){
						aux.pb(s[s.size()-1]);
						s.pop_back();
						cnt--;
					}
					reverse(all(aux));
					ans.pb(aux);
				}

				fr(k,amtq){
					int cnt = q;
					string aux;
					while(cnt){
						aux.pb(s[s.size()-1]);
						s.pop_back();
						cnt--;
					}
					reverse(all(aux));
					ans.pb(aux);
				}

				reverse(all(ans));
				for(auto x : ans)
					cout << x << endl;

				return 0;

			}
		}
	}

	cout << -1 << endl;
	
}