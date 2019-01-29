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

int main(){

	fastio;

	vector<string> repo;

	int n; cin >> n;

	fr(i,n){
		string s; cin >> s;
		repo.pb(s);
	}


	int cnt = 0;

	for(int i=n-1;i>0;i--){

		string& sa = repo[i];
		string& sb = repo[i-1];

		int lena = sa.size();
		int lenb = sb.size();
		int len = min(lena,lenb);
		
		bool flag = false;

		fr(j,len){

			if(sa[j]>sb[j]){
				flag=true;
				break;
			}
			
			if(sa[j]<sb[j]){
				while(lenb>=j+1){
					lenb--;
					sb.pop_back();
				}
				flag=true;
				break;
			}

		}

		if(flag)	continue;

		if(lena<lenb){
		
			while(lenb>lena){
				lenb--;
				sb.pop_back();
			}

		}

	}

	for(auto x : repo)
		cout << x << endl;

}
